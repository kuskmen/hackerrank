uing System.Collections.Generic;
using System.Linq;
using System.Text;
using System;

class Solution
{

     static void countSort(List<List<string>> arr)
     {
        var res = new List<string>[100];
     	
		int i = 0;
        while (i < 100)
        {
           res[i] = new List<string>();
           i++;
        }

        i = 0;
        while (i < arr.Count)
        {
            if (i < arr.Count / 2)
        		res[int.Parse(arr[i][0])].Add("-");
           	else
              	res[int.Parse(arr[i][0])].Add(arr[i][1]);
			i++;
		}

		var sb = new StringBuilder();
		foreach (var item in res)
		{
			foreach (var str in item)
			{
				sb.Append(str).Append(" ");
			}
		}
		
		Console.WriteLine(sb.ToString());
	}

	static void Main(string[] args)
	{
		int n = Convert.ToInt32(Console.ReadLine().Trim());
		List<List<string>> arr = new List<List<string>>();
		for (int i = 0; i < n; i++)
		{
			arr.Add(Console.ReadLine().TrimEnd().Split(' ').ToList());
		}
		
		countSort(arr);
	}
}
			                                                                                                                                                                                                                                                                                                                                                     
