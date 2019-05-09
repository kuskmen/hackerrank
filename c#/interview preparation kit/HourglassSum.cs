class HourglassSum
{
    // Complete the hourglassSum function below.
    public static int hourglassSum(int[][] arr)
    {
        int sum = int.MinValue;
        int i = 0;
        while (i < 4)
        {
            int k = 0;
            while (k < 4)
            {
                var candidateSum = arr[i][k] + arr[i][k + 1] + arr[i][k + 2]
                                    + arr[i + 1][k + 1]
                                    + arr[i + 2][k] + arr[i + 2][k + 1] + arr[i + 2][k + 2];
                if (sum < candidateSum) sum = candidateSum;
                k++;
            }
            i++;
        }
        return sum;
    }
}
