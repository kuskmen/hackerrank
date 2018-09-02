using System;

class InsertionSortTwo
{
    static void insertionSort2(int n, int[] arr)
    {
        for (int i = 0; i < n - 1; i++)
        {
            var j = i;
            while (j >= 0 && arr[j + 1] < arr[j])
            {
                var temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                j--;
            }

            foreach (var item in arr)
            {
                Console.Write(item + " ");
            }

            Console.WriteLine();
        }
    }
}
