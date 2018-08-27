using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

class Solution 
{
    static int getTotalX(int[] a, int[] b)
    {
        var start = a[a.Length - 1];
        var end = b[0];
        var result = 0;

        while (start <= end)
        {
            var index = 0;
            while (index < a.Length && start % a[index] == 0)
            {
	            index++;
		    }

            var index2 = 0;
            while (index2 < b.Length && b[index2] % start == 0)
            {
                index2++;
            }

            if (index == a.Length && index2 == b.Length) result++;

            start++;
        }

        return result;

     }

     static void Main(string[] args) 
	 {
        TextWriter tw = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        string[] nm = Console.ReadLine().Split(' ');

        int n = Convert.ToInt32(nm[0]);

        int m = Convert.ToInt32(nm[1]);

        int[] a = Array.ConvertAll(Console.ReadLine().Split(' '), aTemp => Convert.ToInt32(aTemp));
																		       

        int[] b = Array.ConvertAll(Console.ReadLine().Split(' '), bTemp => Convert.ToInt32(bTemp));
																				        
		int total = getTotalX(a, b);

		tw.WriteLine(total);

        tw.Flush();
        tw.Close();
    }
}

