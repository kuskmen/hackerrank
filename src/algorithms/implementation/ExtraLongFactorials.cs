using System;
using System.Numerics;

namespace HackerRank.algorithms.implementation
{
    public class ExtraLongFactorials
    {
        public static void extraLongFactorials(int n)
        {
            var result = BigInteger.One;
            while (n > 0)
            {
                result *= n;
                n--;
            }

            Console.WriteLine(result);
        }
    }
}
