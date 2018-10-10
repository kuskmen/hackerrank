namespace HackerRank.algorithms.implementation
{
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
}
