using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp1
{
    public class PrimeNumber
    {
        public static bool isPrime(int num)
        {
            int number = num;
            for (int i = 2; i < number / 2; i++)
            {
                if (number % i == 0)
                {
                    return false;
                }
            }
            return true;
        }
        public static List<string> allPrimeInRange(int startnumber, int endnumber)
        {
            List<string> primeNumbers = new List<string>();
            for (int i = startnumber; i <= endnumber; i++)
            {
                if (isPrime(i)) primeNumbers.Add(i.ToString());
            }
            return primeNumbers;
        }
    }
}
