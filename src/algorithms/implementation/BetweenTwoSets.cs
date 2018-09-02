class BetweenTwoSets
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
}

