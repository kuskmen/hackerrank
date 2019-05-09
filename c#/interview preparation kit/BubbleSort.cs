namespace HackerRank.interview_preparation_kit
{
    using System;

    public class BubbleSort
    {
        public static void countSwaps(int[] a)
        {
            var swaps = 0;
            for (int i = 0; i < a.Length - 1; i++)
            {
                for (int j = 0; j < a.Length - i - 1; j++)
                {
                    if (a[j] > a[j + 1])
                    {
                        var temp = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = temp;
                        swaps++;
                    }
                }
            }

            Console.WriteLine($"Array is sorted in {swaps} swaps.");
            Console.WriteLine($"First element: {a[0]}");
            Console.WriteLine($"Last element: {a[a.Length - 1]}");
        }
    }
}