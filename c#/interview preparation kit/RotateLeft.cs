namespace HackerRank.interview_preparation_kit
{
    public class RotateLeft
    {
        public static int[] rotateLeft(int[] a, int d)
        {
            var b = new int[a.Length];
            for (var i = 0; i < a.Length; i++)
            {
                var offset = i - d;

                if (offset < 0)
                {
                    b[a.Length + offset] = a[i];
                    continue;
                }

                b[offset] = a[i];
            }

            return b;
        }
    }
}
