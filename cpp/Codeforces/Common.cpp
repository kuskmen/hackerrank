#include "Common.h"

std::vector<int> KnuthMorrisPratt(std::string text, std::string pattern)
{
	std::vector<int> indexes;
	int text_len = 0, pattern_len = 0;
	for (; text[text_len]; ++text_len);
	for (; pattern[pattern_len]; ++pattern_len);

	auto pre_process_pattern = [](std::string pattern, int pattern_len) -> std::vector<int>
	{
		std::vector<int> lps(pattern_len, 0);
		auto i = 0, len = 0;
		lps[i] = 0;
		i++;

		while (i < pattern_len)
		{
			if (pattern[len] == pattern[i])
			{
				len++;
				lps[i] = len;
				i++;
			}
			else if (len > 0)
			{
				len = lps[len - 1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}

		return lps;
	};

	auto lps = pre_process_pattern(pattern, pattern_len);
	int i = 0, j = 0;
	while (i < text_len)
	{
		if (text[i] == pattern[j])
		{
			i++; j++;

			if (j == pattern_len)
			{
				indexes.emplace_back(i - j);
				j = lps[j - 1];
			}
		}
		else if (j > 0)
			j = lps[j - 1];
		else
			i++;
	}

	return indexes;
}