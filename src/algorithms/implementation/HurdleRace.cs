namespace HackerRank.algorithms.implementation
{
    using System.Linq;

    public class HurdleRace
    {
        public static int hurdleRace(int k, int[] height)
        {
            var max = height.Max();
            return max - k > 0 ? max - k : 0;
        }
    }
}
