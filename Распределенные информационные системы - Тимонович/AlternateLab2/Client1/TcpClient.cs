using System;
using System.Globalization;
using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;

namespace Client1
{
    internal static class TcpClient
    {
        public static void Main()
        {
            try
            {
                var i = 0;
                var client = new System.Net.Sockets.TcpClient();
                client.Connect(Dns.GetHostName(), 2055);
                var stream = client.GetStream();
                while (i < 3)
                {
                    var message = DateTime.Now.ToString(CultureInfo.InvariantCulture);
                    var data = Encoding.ASCII.GetBytes(message);
                    stream.Write(data, 0, data.Length);
                    Console.WriteLine("Sent: {0}", message);
                    data = new byte[256];
                    var bytes = stream.Read(data, 0, data.Length);
                    var responseData = Encoding.ASCII.GetString(data, 0, bytes);
                    Console.WriteLine("Received: {0}", responseData);
                    i++;
                    WriteToFile("client1 " + message);
                    Console.WriteLine("client 1 finished work.");
                    stream.Write(new byte[256], 0, data.Length);
                }

                stream.Close();
                client.Close();
            }
            catch (ArgumentNullException e)
            {
                Console.WriteLine("ArgumentNullException: {0}", e);
            }
            catch (SocketException e)
            {
                Console.WriteLine("SocketException: {0}", e);
            }

            Console.WriteLine("\n Press Enter to continue...");
            Console.ReadLine();
        }



        private static void WriteToFile(string message)
        {
            message += "\n";
            using (var writer = new FileStream(@"D:\TextFile.txt", FileMode.Append))
            {
                var i = 0;
                while (i < 5)
                {
                    var data = new UTF8Encoding(true).GetBytes(message);
                    writer.Write(data, 0, message.Length);
                    i++;
                    Thread.Sleep(1000);
                }
            }
        }
    }
}