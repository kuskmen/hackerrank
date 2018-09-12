using System;
using System.Collections.Generic;

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