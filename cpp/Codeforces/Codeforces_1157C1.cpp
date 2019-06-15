#include <iostream>
#include <algorithm>
#include <list>

#include "Codeforces.h"

/*	You are given a sequence a consisting of n integers.All these integers are distinct, each value 
 *  from 1 to n appears in the sequence exactly once.
 *
 *	You are making a sequence of moves.During each move you must take either the leftmost element 
 *  of the sequence or the rightmost element of the sequence, write it downand remove it from the 
 *  sequence.Your task is to write down a strictly increasing sequence, and among all such sequences 
 *  you should take the longest(the length of the sequence is the number of elements in it).
 *
 *	For example, for the sequence[2, 1, 5, 4, 3] the answer is 4 (you take 2 and the sequence 
 *  becomes[1, 5, 4, 3], then you take the rightmost element 3 and the sequence becomes[1, 5, 4], 
 *	then you take 4 and the sequence becomes[1, 5] and then you take 5 and the sequence becomes[1], 
 *	the obtained increasing sequence is[2, 3, 4, 5]).
 *
 *	Input
 *	The first line of the input contains one integer n(1≤n≤2⋅10^5) — the number of elements in a.
 *	The second line of the input contains n integers a1, a2, …, an(1≤ai≤n), where ai is the i - th 
 *  element of a.All these integers are pairwise distinct.
 *
 *	Output
 *	In the first line of the output print k — the maximum number of elements in a strictly increasing 
 *  sequence you can obtain.
 *	In the second line print a string s of length k, where the j - th character of this string sj 
 *  should be 'L' if you take the leftmost element during the j - th move and 'R' otherwise.
 *  If there are multiple answers, you can print any.
 */
/*
	Difficulty: 1300
*/
/*
 * Comlexity : O(n)
 * Memory    : O(m) where m =< n
 */

int Codeforces_1157C1()
{
	long length;
	std::cin >> length;
	std::list<int> sequence;
	for (int i = 0; i < length; ++i)
	{
		int num;
		std::cin >> num;
		sequence.emplace_back(num);
	}

	std::string result;
	auto operate = [](std::string & operations, std::list<int> & sequence, int comparing)
	{
		if (comparing == sequence.front())
		{
			sequence.pop_front();
			operations += "L";
		}
		else
		{
			sequence.pop_back();
			operations += "R";
		}
	};

	int min = std::min(sequence.front(), sequence.back());
	std::string operations{};

	operate(operations, sequence, min);

	while (!sequence.empty())
	{
		int front = sequence.front();
		int back = sequence.back();

		int greater = std::min(front, back) < min ? std::max(front, back) : std::min(front, back);

		if (greater < min) break;

		min = greater;

		operate(operations, sequence, greater);
	}

	result = result.size() > operations.size() ? result : operations;

	std::cout << result.size() << std::endl << result;
	return 0;
}