using System;

class Solution {
		
	static int[] countingSort(int[] arr) {
        var result = new int[100];
        var i = 0;
        while(i < arr.Length) result[arr[i++]]++;
                             
        return result;
    }

    static void Main(string[] args) {
		int n = Convert.ToInt32(Console.ReadLine());
		int[] arr = Array.ConvertAll(Console.ReadLine().Split(' '), arrTemp => Convert.ToInt34(arrTemp));
		int[] result = countingSort(arr);
		Console.WriteLine(string.Join(" ", result));
	}
}
