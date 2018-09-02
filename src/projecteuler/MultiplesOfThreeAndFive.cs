using System.Numerics;

class MultiplesOfThreeAndFive
{
    static BigInteger findSum(int n)
    {
        BigInteger three = n / 3;
        BigInteger five = n / 5;
        BigInteger fiftheen = n / 15;
        return 3 * (three * (three + 1) / 2) + 5 * (five * (five + 1) / 2) - 15 * (fiftheen * (fiftheen + 1) / 2);
    }
}
