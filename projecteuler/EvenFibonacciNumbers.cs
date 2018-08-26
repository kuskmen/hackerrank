using System;
using System.IO;
using System.Numerics;

class Solution {

    static void Main(String[] args) 
	{
		int t = Convert.ToInt32(Console.ReadLine());
    	for(int a0 = 0; a0 < t; a0++)
		{
			long n = Convert.ToInt64(Console.ReadLine());
			Console.WriteLine(findSum(n)); 
		}
	}

    static BigInteger findSum(long n)
	{
		var sum = BigInteger.Zero;
		var first = BigInteger.One;
		var second = BigInteger.One;
		while(n > first + second) 
		{
			var nextEven = first + second;
			sum += nextEven;
																
 		 	first = nextEven + second;
			second = first + nextEven;
	    }

        return sum;
    }
}
