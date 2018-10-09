namespace HackerRank.algorithms.implementation
{
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
}
