namespace HackerRank.algorithms.implementation
{
    public static class PdfViewer
    {
        public static int DesignerPdfViewer(int[] h, string word)
        {
            const string englishAlphabet = "abcdefghijklmnopqrstuvwxyz";
            var maxHeight = 1;

            foreach (var ch in word)
            {
                var height = h[englishAlphabet.IndexOf(ch)];
                if (height > maxHeight)
                {
                    maxHeight = height;
                }
            }
            return word.Length * maxHeight;
        }
    }
}
