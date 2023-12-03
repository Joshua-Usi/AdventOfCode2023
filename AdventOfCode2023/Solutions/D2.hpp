#pragma once
namespace AOC::D2
{
	int x = []() {
		SolutionsManager::RegisterSolution("D2P1", [](std::string& input) -> std::string {
			std::unordered_map<std::string, uint32_t> maxCounts{ { "red", 12 }, { "green", 13 }, { "blue", 14 } };
			std::vector<std::string> games = split(input, '\n');
			uint32_t sum = 0;
			for (auto& game : games)
			{
				std::vector<std::string> gameData = split(game, ':');
				std::string id = split(gameData[0], ' ')[1];
				std::vector<std::string> sequence = split(gameData[1], ';');
				bool isValidGame = true;
				for (auto& seq : sequence)
				{
					std::vector<std::string> subseq = split(seq, ',');
					std::unordered_map<std::string, uint32_t> counts;
					for (auto& sub : subseq)
					{
						std::vector<std::string> subsubseq = split(sub, ' ');
						counts[subsubseq[1]] += std::stoi(subsubseq[0]);
					}
					for (const auto& [color, count] : counts)
					{
						if (count > maxCounts.at(color))
						{
							isValidGame = false;
							break;
						}
					}
					if (!isValidGame) break;
				}
				if (isValidGame) sum += std::stoi(id);
			}
			return std::to_string(sum);
		});
		SolutionsManager::RegisterSolution("D2P2", [](std::string& input) -> std::string {
			std::vector<std::string> games = split(input, '\n');
			uint32_t sum = 0;
			for (auto& game : games)
			{
				std::vector<std::string> gameData = split(game, ':');
				std::string id = split(gameData[0], ' ')[1];
				std::vector<std::string> sequence = split(gameData[1], ';');
				std::unordered_map<std::string, uint32_t> minCounts;
				for (auto& seq : sequence)
				{
					std::vector<std::string> subseq = split(seq, ',');
					for (auto& sub : subseq)
					{
						std::vector<std::string> subsubseq = split(sub, ' ');
						minCounts[subsubseq[1]] = std::max(minCounts[subsubseq[1]], static_cast<uint32_t>(std::stoi(subsubseq[0])));
					}
				}
				sum += minCounts["red"] * minCounts["green"] * minCounts["blue"];
			}
			return std::to_string(sum);
		});
		return 0;
	}();
}
