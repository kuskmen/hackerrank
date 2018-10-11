using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;

public class BetweenTwoSets
{
    public static int getTotalX(int[] a, int[] b)
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

public class BonAppetit
{

    // Complete the bonAppetit function below.
    public static void bonAppetit(List<int> bill, int k, int b)
    {
        var actualB = 0;
        for (var i = 0; i < bill.Count; i++)
        {
            if (i == k) continue;
            actualB += bill[i];
        }

        actualB /= 2;

        Console.WriteLine(b == actualB ? "Bon Appetit" : (b - actualB).ToString());
    }
}

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

public class ExtraLongFactorials
{
    public static void extraLongFactorials(int n)
    {
        var result = BigInteger.One;
        while (n > 0)
        {
            result *= n;
            n--;
        }

        Console.WriteLine(result);
    }
}

public class FindDigits
{
    public static int findDigits(int n)
    {
        var digits = n.ToString();
        var result = 0;

        foreach (var digitCh in digits)
        {
            var digit = int.Parse(digitCh.ToString());
            if (digit == 0) continue;

            if (n % digit == 0) result += 1;
        }

        return result;
    }
}

public class HurdleRace
{
    public static int hurdleRace(int k, int[] height)
    {
        var max = height.Max();
        return max - k > 0 ? max - k : 0;
    }
}

public class JumpingOnTheClouds
{
    public static int jumpingOnClouds(int[] c, int k)
    {
        var energy = 100;
        var nextCloudIndex = 0;

        while (true)
        {
            nextCloudIndex += k;
            energy -= c[nextCloudIndex % c.Length] == 1 ? 3 : 1;

            if (nextCloudIndex % c.Length == 0) return energy;
        }
    }
}

public static class PdfViewer
{
    public static int DesignerPdfViewer(int[] h, string word)
    {
        const string englishAlphabet = "abcdefghijklmnopqrstuvwxyz";
        var maxHeight = 1;

        foreach (var ch in word)
        {
            var height = h[englishAlphabet.IndexOf(ch)];
            if (height > maxHeight)
            {
                maxHeight = height;
            }
        }
        return word.Length * maxHeight;
    }
}