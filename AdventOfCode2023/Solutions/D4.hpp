#pragma once

namespace AOC::D4
{
	int x = []() {
		SolutionsManager::Register("D4P1", [](std::string& input) -> std::string {
			input = replace(input, "  ", " ");
			std::vector<std::string> lines = split(input, '\n');
			uint32_t points = 0;
			for (auto& line : lines)
			{
				std::vector<std::string> game = split(line, ':');
				std::vector<std::string> scratchie = split(game[1], '|');
				std::vector<std::string> sc = split(scratchie[0], ' ');
				std::vector<std::string> wn = split(scratchie[1], ' ');

				std::unordered_set<std::string> scratchieNumbers;
				for (auto& s : sc) scratchieNumbers.insert(s);

				uint32_t scratchieWins = 0;

				for (auto& w : wn)
				{
					if (scratchieNumbers.find(w) != scratchieNumbers.end())
					{
						if (scratchieWins == 0) scratchieWins++;
						else scratchieWins *= 2;
					}
				}
				points += scratchieWins;
			}
			return std::to_string(points);
		});
		SolutionsManager::Register("D4P2", [](std::string& input) -> std::string {
			input = replace(input, "  ", " ");
			std::vector<std::string> lines = split(input, '\n');
			std::vector<uint32_t> copies(lines.size(), 1);
			uint32_t totalCards = 0;
			for (uint32_t i = 0; i < lines.size(); i++)
			{
				auto& line = lines[i];

				std::vector<std::string> game = split(line, ':');
				std::vector<std::string> scratchie = split(game[1], '|');
				std::vector<std::string> sc = split(scratchie[0], ' ');
				std::vector<std::string> wn = split(scratchie[1], ' ');

				std::unordered_set<std::string> scratchieNumbers;
				for (auto& s : sc) scratchieNumbers.insert(s);
				uint32_t matches = 0;
				for (auto& w : wn) matches += scratchieNumbers.find(w) != scratchieNumbers.end();

				for (uint32_t j = 1; j <= matches; j++)
				{
					if (i + j < lines.size()) copies[i + j] += copies[i];
				}

				totalCards += copies[i];
			}
			return std::to_string(totalCards);
		});
		return 0;
	}();
}
