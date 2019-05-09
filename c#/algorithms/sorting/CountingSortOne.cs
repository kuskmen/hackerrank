class CountingSortOne
{
    static int[] countingSort(int[] arr)
    {
        var result = new int[100];
        var i = 0;
        while (i < arr.Length) result[arr[i++]]++;

        return result;
    }
}
