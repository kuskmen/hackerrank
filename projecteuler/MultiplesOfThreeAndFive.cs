using System;
using System.IO;
using System.Numerics;

class Solution {

    static void Main(String[] args) 
	{
      	 int t = Convert.ToInt32(Console.ReadLine());
   	     for(int a0 = 0; a0 < t; a0++)
   		 {
   	     	int n = Convert.ToInt32(Console.ReadLine());
   	        Console.WriteLine(findSum(--n));
   	     }
    }

	static BigInteger findSum(int n)
	{
		BigInteger three = n / 3;
        BigInteger five = n / 5;
		BigInteger fiftheen = n / 15;
		return 3 * (three * (three + 1) / 2) + 5 * (five * (five + 1) / 2) - 15 * (fiftheen * (fiftheen + 1) / 2);
	}
}
