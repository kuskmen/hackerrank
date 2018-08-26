using System;
using System.Numerics;

class Solution
{

    static void Main(String[] args)
    {
	     int t = Convert.ToInt32(Console.ReadLine());
	     for (int a0 = 0; a0 < t; a0++)
	     {
	         var n = Convert.ToInt64(Console.ReadLine());
	         Console.WriteLine(FindLargestPrimeFactor(n));
	     }
	}

	public static long FindLargestPrimeFactor(long n)
	{
		 if (IsPrime(n)) return n;
	     if (n !=0 && (n & (n - 1)) == 0) return 2;

	     var sqrt = (int) Math.Sqrt(n);
	     var largestPrime = 2;
	     var prime = 2;
																        
	     while(prime <= sqrt) {
		     while(n % prime == 0) {
			     n /= prime;
			     largestPrime = prime;
			 }
															            
			 prime++;
		 }
																					        
		 return n > 2 ? n : largestPrime;
	 }
				    
	 public static bool IsPrime(long number)
	 {
	     var square = (int)Math.Sqrt(number);

         while (number % square != 0 && square != 1)
         {
	         square--;
	     }

         return square == 1;
      }
}
