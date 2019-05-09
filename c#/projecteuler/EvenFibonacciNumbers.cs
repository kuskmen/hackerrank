using System.Numerics;

class EvenFibonacciNumbers
{
    static BigInteger findSum(long n)
    {
        var sum = BigInteger.Zero;
        var first = BigInteger.One;
        var second = BigInteger.One;
        while (n > first + second)
        {
            var nextEven = first + second;
            sum += nextEven;

            first = nextEven + second;
            second = first + nextEven;
        }

        return sum;
    }
}
