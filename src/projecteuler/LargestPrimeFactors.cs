using System;

class LargestPrimeFactors
{
    public static long FindLargestPrimeFactor(long n)
    {
        if (IsPrime(n)) return n;
        if (n != 0 && (n & (n - 1)) == 0) return 2;

        var sqrt = (int)Math.Sqrt(n);
        var largestPrime = 2;
        var prime = 2;

        while (prime <= sqrt)
        {
            while (n % prime == 0)
            {
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
