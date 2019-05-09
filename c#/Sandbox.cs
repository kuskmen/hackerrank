//Merge Sort
using System;
class Solution
{
    static void Main(String[] args)
    {
        //Initializing array
        int[] arr = { 9, 4, 8, 3, 1, 2, 5 };
        Console.Write("Initial Array: ");
        printArray(arr, 0, arr.Length - 1);
        Console.WriteLine();
        mergesort(arr, 0, arr.Length - 1);
    }
    //Sorting in non decreasing order
    private static void mergesort(int[] arr, int i, int j)
    {
        // TODO Auto-generated method stub
        int mid = 0;

        if (i < j)
        {
            mid = (i + j) / 2;
            // Console.WriteLine("mid="+mid);
            mergesort(arr, i, mid);
            mergesort(arr, mid + 1, j);
            merge(arr, i, mid, j);
        }
    }

    private static void merge(int[] arr, int i, int mid, int j)
    {
        Console.Write("Left: ");
        printArray(arr, i, mid);
        Console.Write(" Right: ");
        printArray(arr, mid + 1, j);
        Console.WriteLine();
        int[] temp = new int[arr.Length];
        int l = i;
        int r = j;
        int m = mid + 1;
        int k = l;

        while (l <= mid && m <= r)
        {
            if (arr[l] <= arr[m])
            {
                temp[k++] = arr[l++];
            }
            else
            {
                temp[k++] = arr[m++];
            }
        }

        while (l <= mid)
            temp[k++] = arr[l++];

        while (m <= r)
        {
            //Console.WriteLine("m="+m);
            temp[k++] = arr[m++];
        }

        for (int i1 = i; i1 <= j; i1++)
        {
            arr[i1] = temp[i1];
        }

        Console.Write("After Merge: ");
        printArray(arr, i, j);
        Console.WriteLine();
    }
    private static void printArray(int[] arr, int i, int j)
    {
        Console.Write("[");

        for (int k = i; k < j; k++)
        {
            Console.Write(arr[k] + ", ");
        }

        Console.Write(arr[j] + "]");
    }

}