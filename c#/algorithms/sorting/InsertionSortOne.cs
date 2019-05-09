using System;

class InsertionSortOne
{
    static void insertionSort1(int n, int[] arr)
    {
        var term = arr[--n];

        while (n > 0 && arr[n - 1] > term)
        {
            arr[n] = arr[n - 1];

            foreach (var number in arr)
            {
                Console.Write($"{number} ");
            }

            Console.WriteLine();
            n--;
        }

        arr[n] = term;

        foreach (var number in arr)
        {
            Console.Write($"{number} ");
        }
    }
}
