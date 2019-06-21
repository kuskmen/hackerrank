#include <iostream>
#include <regex>
#include <string>
#include "Codeforces.h"

/*
	In the popular spreadsheets systems (for example, in Excel) the following numeration of 
	columns is used. The first column has number A, the second — number B, etc. till column 26 
	that is marked by Z. Then there are two-letter numbers: column 27 has number AA, 28 — AB, 
	column 52 is marked by AZ. After ZZ there follow three-letter numbers, etc.

	The rows are marked by integer numbers starting with 1. The cell name is the concatenation 
	of the column and the row numbers. For example, BC23 is the name for the cell that is in 
	column 55, row 23.

	Sometimes another numeration system is used: RXCY, where X and Y are integer numbers, showing 
	the column and the row numbers respectfully. For instance, R23C55 is the cell from the previous
	example.

	Your task is to write a program that reads the given sequence of cell coordinates and produce 
	each item written according to the rules of another numeration system.

	Input
	The first line of the input contains integer number n (1 ≤ n ≤ 10^5), the number of coordinates 
	in the test. Then there follow n lines, each of them contains coordinates. All the coordinates 
	are correct, there are no cells with the column and/or the row numbers larger than 10^6.

	Output
	Write n lines, each line should contain a cell coordinates in the other numeration system.
 */
/*
	Difficulty: 1700
 */
/*
	Complexity: 
	Memory: 
 */
int Codeforces_1B()
{
	int n;
	std::cin >> n;

	std::vector<std::string> coordinates;
	
	coordinates.reserve(n);
	for (int i = 0; i < n; i++)
	{
		std::string coordinate;
		std::cin >> coordinate;

		coordinates.emplace_back(coordinate);
	}

	std::string alphabet("0ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	std::regex second_type("R\\d+C\\d+");

	for (int i = 0; i < n; i++)
	{
		std::regex coordinate("\\d+");
		std::sregex_iterator next(coordinates[i].begin(), coordinates[i].end(), coordinate);
		if (std::regex_match(coordinates[i], second_type))
		{
			int row = std::stoi((*next).str());
			++next;
			int column = std::stoi((*next).str());

			int index = 0;
			while (column > 26)
			{
				column -= 26;
				++index;
			}

			std::string col;
			if (index == 0)
				col = alphabet[column];
			else
				col = std::string({ alphabet[index % 26], alphabet[column] });
			
			std::cout << col << row << std::endl;
		}
		else
		{
			int row = std::stoi((*next).str());
			
			int chars = 0;
			char c = coordinates[i][chars];
			std::string letters;
			while (c >= 'A' && c <= 'Z' && ++chars)
			{
				letters.append(std::string(1, c));
				c = coordinates[i][chars];
			}

			int column = 0;
			for (auto letter = 0; letter < letters.size() - 1; ++letter)
				column += alphabet.find(letters[letter]) * 26;
			column += alphabet.find(letters[letters.size() - 1]);

			std::cout << "R" << row << "C" << column << std::endl;
		}
	}

	return 0;
}