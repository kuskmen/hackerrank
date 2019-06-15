#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

#include "Codeforces.h"

/*
	The winner of the card game popular in Berland "Berlogging" is 
	determined according to the following rules. 
	
	If at the end of the game there is only one player with the maximum number of points, 
	he is the winner. The situation becomes more difficult if the number of such players 
	is more than one. During each round a player gains or loses a particular number of points. 
	
	In the course of the game the number of points is registered in the line "name score", 
	where name is a player's name, and score is the number of points gained in this round, 
	which is an integer number. If score is negative, this means that the player has lost 
	in the round. So, if two or more players have the maximum number of points (say, it equals to m) 
	at the end of the game, than wins the one of them who scored at least m points first. 
	
	Initially each player has 0 points. It's guaranteed that at the end of the game at least 
	one player has a positive number of points.


	Input
	The first line contains an integer number n (1  ≤  n  ≤  1000), 
	n is the number of rounds played. Then follow n lines, containing the information 
	about the rounds in "name score" format in chronological order, 
	where name is a string of lower-case Latin letters with the length from 1 to 32, 
	and score is an integer number between -1000 and 1000, inclusive.

	Output
	Print the name of the winner.
 */
/*
	Difficulty: 1600
 */
/*
	Complexity: O(n)
	Memory: O(m)
 */
int Codeforces_2A()
{
	int n;
	std::cin >> n;

	std::vector<std::pair<std::string, int>> participants;
	std::map<std::string, int> cumulative_points;
	std::map<std::string, int> earned_points;
	std::string name;
	int points;

	for (int i = 0; i < n; i++)
	{
		std::cin >> name >> points;

		participants.emplace_back(name, points);
		cumulative_points.emplace(name, 0);

		if (earned_points.find(name) == earned_points.end())
			earned_points.emplace(name, points);
		else
			earned_points[name] += points;
	}

	auto max_points = *std::max_element(
		earned_points.begin(),
		earned_points.end(), [](const auto lhs, const auto rhs)
	{
		return lhs.second < rhs.second;
	});

	auto winner = *std::max_element(
		earned_points.begin(), 
		earned_points.end(), [&participants, &max_points](auto lhs, auto rhs) 
	{
		if (lhs.second < rhs.second)
			return true;
		else if (lhs.second == rhs.second)
		{
			auto lhs_points = 0, rhs_points = 0;
			for (auto participant : participants)
			{
				if (participant.first == lhs.first)
				{
					lhs_points += participant.second;

					if (lhs_points >= max_points.second)
						return false;
				}
				else if (participant.first == rhs.first)
				{
					rhs_points += participant.second;

					if (rhs_points >= max_points.second)
						return true;
				}
			}
		}
		else
			return false;
	});

	std::cout << winner.first << std::endl;
	return 0;
}