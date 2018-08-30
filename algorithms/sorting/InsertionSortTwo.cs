using System;

class Solution
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

                                                                                                                         static void Main(string[] args)
     {
                                                                                                                                int n = Convert.ToInt32(Console.ReadLine());
            int[] arr = Array.ConvertAll(Console.ReadLine().Split(' '), Convert.ToInt32);
            insertionSort2(n, arr);
     }
}
