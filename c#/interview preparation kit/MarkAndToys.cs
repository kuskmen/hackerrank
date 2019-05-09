using System;

namespace HackerRank.interview_preparation_kit
{
    public class MarkAndToys
    {
        public static int maximumToys(int[] prices, int k)
        {
            Array.Sort(prices);
            var i = 0;

            while (k > 0 && i < prices.Length - 1)
            {
                k -= prices[i];
                if (k > 0) i++;
            }

            return i;
        }
    }
}
