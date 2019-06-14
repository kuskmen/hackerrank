#include <iostream>
#include <vector>
#include <set>

#include "Codeforces.h"
/*
 * You are given two arrays a and b, both of length n. All elements of both 
 * arrays are from 0 to n−1. You can reorder elements of the array b 
 * (if you want, you may leave the order of elements as it is). After that, let array c be 
 * the array of length n, the i-th element of this array is ci=(ai+bi)%n, where x%y is x modulo y.
 * 
 * Your task is to reorder elements of the array b to obtain the lexicographically minimum 
 * possible array c. Array x of length n is lexicographically less than array y of length n, 
 * if there exists such i (1≤i≤n), that xi<yi, and for any j (1≤j<i) xj=yj.
 *
 * Input
 * (The first line of the input contains one integer n (1≤n≤2⋅10^5) — the number of 
 * elements in a, b and c.
 *
 * The second line of the input contains n integers a1,a2,…,an (0≤ai<n), where ai is the i-th 
 * element of a. The third line of the input contains n integers b1,b2,…,bn (0≤bi<n), 
 * where bi is the i-th element of b.
 *
 * Output
 * Print the lexicographically minimum possible array c. Recall that your task is to reorder 
 * elements of the array b and obtain the lexicographically minimum possible array c, where 
 * the i-th element of c is ci=(ai+bi)%n.
 */
/*
	Difficulty: 1700
*/
/*
	Complexity: O(nlogn)
	Memory: O(1)

 */
void Codeforces_1157E()
{
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	
	std::multiset<int> b;
	for (int i = 0; i < n; ++i)
	{
		int x;
		std::cin >> x;
		b.insert(x);
	}

	for (int i = 0; i < n; ++i)
	{
		auto x = b.lower_bound(n - a[i]);
		if (x == b.end()) 
			x = b.begin();
		std::cout << (a[i] + *x) % n << " ";
		
		b.erase(x);
	}
}
