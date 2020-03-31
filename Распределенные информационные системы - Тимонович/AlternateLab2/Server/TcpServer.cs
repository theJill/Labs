using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;

namespace Server
{
    internal static class TcpServer
    {
        private static TcpListener _listener;
        private const int Limit = 5;
        private static readonly List<ThreadStatus> Queue = new List<ThreadStatus>();

        public static void Main()
        {
            var localAddress = IPAddress.Parse("192.168.0.102");
            _listener = new TcpListener(localAddress, 2055);
            _listener.Start();
            Console.Write("Waiting for a connection... ");
            for (var i = 0; i < Limit; i++)
            {
                var i1 = i;
                var t = new Thread(() => Service(i1 + 1));
                t.Start();
            }
        }

        private static void Service(int threadNumber)
        {
            var bytes = new byte[256];
            var client = _listener.AcceptTcpClient();
            Console.WriteLine("Client connected!");
            Queue.Add(new ThreadStatus(threadNumber));
            var stream = client.GetStream();
            try
            {
                while (true)
                {
                    stream.Read(bytes, 0, bytes.Length);
                    var data = Encoding.ASCII.GetString(bytes, 0, bytes.Length);
                    Console.WriteLine("Received: {0}", data);
                    Queue.Single(t => t.Number == threadNumber).Time = DateTime.Parse(data);
                    Queue.Single(t => t.Number == threadNumber).Status = Status.Work;
                    while (!AllowWrite(threadNumber))
                    {
                    }

                    var msg = Encoding.ASCII.GetBytes(data);
                    stream.Write(msg, 0, msg.Length);
                    Console.WriteLine("Sent: {0}", data);
                    stream.Read(new byte[256], 0, 256);
                    Queue.Single(t => t.Number == threadNumber).Status = Status.Ok;
                }
            }
            catch (SocketException e)
            {
                Console.WriteLine("SocketException: {0}", e);
            }
            catch
            {
                stream.Close();
            }
        }

        private static bool AllowWrite(int threadNumber)
        {
            if (!Queue.Any(t => t.Status == Status.Work && t.Number != threadNumber))
            {
                return true;
            }

            return Queue.OrderBy(t => t.Time).First().Number == threadNumber;
        }
    }
}