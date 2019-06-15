#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "Codeforces.h"

/*
	Tomorrow Peter has a Biology exam. He does not like this subject much, 
	but d days ago he learnt that he would have to take this exam. 
	Peter's strict parents made him prepare for the exam immediately, 
	for this purpose he has to study not less than minTimei and not more than maxTimei 
	hours per each i-th day. Moreover, they warned Peter that a day before 
	the exam they would check how he has followed their instructions.

	So, today is the day when Peter's parents ask him to show the timetable of 
	his preparatory studies. But the boy has counted only the sum of hours sumTime 
	spent him on preparation, and now he wants to know if he can show his parents 
	a timetable sсhedule with d numbers, where each number sсhedulei stands for the 
	time in hours spent by Peter each i-th day on biology studies, and satisfying the 
	limitations imposed by his parents, and at the same time the sum total of all schedulei 
	should equal to sumTime.

	Input
	The first input line contains two integer numbers d, 
	sumTime (1 ≤ d ≤ 30, 0 ≤ sumTime ≤ 240) — the amount of days, during which Peter studied, 
	and the total amount of hours, spent on preparation. Each of the following d lines contains 
	two integer numbers minTimei, maxTimei (0 ≤ minTimei ≤ maxTimei ≤ 8), 
	separated by a space — minimum and maximum amount of hours that Peter could spent in the 
	i-th day.

	Output
	In the first line print YES, and in the second line print d numbers (separated by a space), 
	each of the numbers — amount of hours, spent by Peter on preparation in the corresponding day, 
	if he followed his parents' instructions; or print NO in the unique line. 
	If there are many solutions, print any of them.
 */
/*
	Difficulty: 1500
 */
/*
	Complexity: O(n)
	Memory: O(m)
 */
int Codeforces_4B()
{
	int d, sumTime;
	std::cin >> d >> sumTime;
	std::vector<std::pair<int, int>> days;

	int minSum = 0, maxSum = 0;
	for (int i = 0; i < d; i++)
	{
		int min, max;
		std::cin >> min >> max; 
		days.emplace_back(min, max);
		minSum += min;
		maxSum += max;
	}
	
	if (sumTime < minSum || sumTime > maxSum)
	{
		std::cout << "NO\n";
		return 0;
	}

	std::vector<std::pair<int, int>> max_schedule;
	for (int i = 0; i < d; i++)
		max_schedule.emplace_back(days[i].second, i);

	std::sort(max_schedule.begin(), max_schedule.end(), [](auto lhs, auto rhs)
	{
		return lhs.first < rhs.first;
	});

	std::vector<std::pair<int, int>> min_schedule;
	for (size_t i = 0; i < d; i++)
		min_schedule.emplace_back(days[max_schedule[i].second].first, max_schedule[i].second);


	int day = d - 1;
	int toFill = sumTime - minSum;
	while (toFill >= 0 && day >= 0)
	{
		int margin = max_schedule[day].first - min_schedule[day].first;
		if (margin >= toFill)
		{
			min_schedule[day].first += toFill;
			toFill = 0;

			std::cout << "YES\n";
			std::sort(min_schedule.begin(), min_schedule.end(), [](auto lhs, auto rhs)
			{
				return lhs.second < rhs.second;
			});
			for (int i = 0; i < d; i++)
				std::cout << min_schedule[i].first << " ";

			return 0;
		}
		else
		{
			min_schedule[day].first += margin;
			toFill -= margin;
		}
		--day;
	}

	return 0;
}