using System;
using System.Runtime.InteropServices;

namespace TestSharp
{
    class Program
    {
        [DllImport(@"D:\Labs\System Programming\Lab3\Debug\DLL3.dll", EntryPoint = "get_time")]
        public static extern long GetTime();

        [STAThread]
        private static void Main()
        {
            var time = new DateTime(1970, 1, 1).AddHours(3).AddSeconds(GetTime());
            Console.WriteLine($"Datetime: {time}.");
        }
    }
}
