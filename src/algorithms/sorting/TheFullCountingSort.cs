using System;
using System.Collections.Generic;
using System.Text;

class TheFullCountingSort
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
}

