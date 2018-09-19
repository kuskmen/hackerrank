using System.Collections.Generic;
using System.Linq;

namespace HackerRank.algorithms.implementation
{
    public static class CutTheSticks
    {
        public static int[] cutTheSticks(int[] arr)
        {
            var res = new List<int>();
            while (arr.Count(i => i != 0) != 0)
            {
                var reductions = 0;
                var min = arr.Where(i => i != 0).Min();
                for (int i = 0; i < arr.Length; i++)
                {
                    if (arr[i] > 0)
                    {
                        arr[i] -= min;
                        reductions++;
                    }
                }
                res.Add(reductions);
            }

            return res.ToArray();
        }
    }
}
