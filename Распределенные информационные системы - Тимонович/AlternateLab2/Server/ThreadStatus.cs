using System;

namespace Server
{
    public class ThreadStatus
    {
        public Status Status;
        public DateTime Time;
        public readonly int Number;

        public ThreadStatus(int number)
        {
            Status = Status.Ok;
            Number = number;
            Time = DateTime.MaxValue;
        }
    }
}