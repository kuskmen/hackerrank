#include <iostream>
#include <algorithm>
#include <vector>

#include "Codeforces.h"
/*
	Toad Ivan has m pairs of integers, each integer is between 1 and n, inclusive. 
	The pairs are (a1,b1),(a2,b2),…,(am,bm).

	He asks you to check if there exist two integers x and y (1≤x<y≤n) such that in each 
	given pair at least one integer is equal to x or y.

	Input
	The first line contains two space-separated integers n and m (2≤n≤300000, 1≤m≤300000) 
	— the upper bound on the values of integers in the pairs, and the number of given pairs.

	The next m lines contain two integers each, the i-th of them contains two space-separated 
	integers ai and bi (1≤ai,bi≤n,ai≠bi) — the integers in the i-th pair.

	Output
	Output "YES" if there exist two integers x and y (1≤x<y≤n) such that in each given pair 
	at least one integer is equal to x or y. Otherwise, print "NO". You can print each letter 
	in any case (upper or lower).
*/
/*
	Difficulty: 1500
*/
/*
	Complexity: O(n)
	Memory: O(m) where m = 2*n+2 
*/
int Codeforces_1169B()
{
	std::pair<int, int> n_m;

	std::cin >> n_m.first;
	std::cin >> n_m.second;

	std::vector<std::pair<int, int>> pairs;
	pairs.reserve(n_m.second);

	for (auto i = 0; i < n_m.second; ++i)
	{
		int x, y;
		std::cin >> x;
		std::cin >> y;

		pairs.emplace_back(x, y);
	}

	std::vector<int> xs{ pairs[0].first, pairs[0].second };

	for(auto x : xs)
	{
		std::vector<int> missing(n_m.first+1);
		int all_missing = 0;
		for (auto pair : pairs)
		{
			if(x != pair.first && x != pair.second)
			{
				missing[pair.first]++;
				missing[pair.second]++;
				all_missing++;
			}
		}

		if (*std::max_element(missing.begin(), missing.end()) == all_missing)
		{
			std::cout << "YES";
			return 0;
		}
	}

	std::cout << "NO";
	return 0;
}