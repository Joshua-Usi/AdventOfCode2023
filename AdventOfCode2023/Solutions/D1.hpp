#pragma once

namespace AOC::D1
{
	uint32_t SumLines(std::vector<std::string>& lines)
	{
		uint32_t sum = 0;
		for (const auto& line : lines)
		{
			uint8_t first = 0, last = 0;
			for (auto& ch : line)
			{
				if (std::isdigit(ch))
				{
					if (first == 0) first = ch - '0';
					last = ch - '0';
				}
			}
			sum += first * 10 + last;
		}
		return sum;
	}
	int x = []() {
		SolutionsManager::Register("D1P1", [](std::string& input) -> std::string {
			std::vector<std::string> lines = split(input, '\n');
			return std::to_string(SumLines(lines));
		});
		SolutionsManager::Register("D1P2", [](std::string& input) -> std::string {
			const std::unordered_map<std::string, std::string> digitMap { {"one", "1"}, {"two", "2"}, {"three", "3"}, {"four", "4"}, {"five", "5"}, {"six", "6"}, {"seven", "7"}, {"eight", "8"}, {"nine", "9"} };
			std::vector<std::string> lines = split(input, '\n');
			for (auto& line : lines)
			{
				size_t pos = 0;
				for (size_t pos = 0, lowest = std::string::npos; pos != std::string::npos; pos = lowest, lowest = std::string::npos)
				{
					std::string replacingText = "";
					for (const auto& [name, digit] : digitMap)
					{
						size_t p = line.find(name);
						replacingText = (p < lowest) ? name : replacingText;
						lowest = std::min(lowest, p);
					}
					if (lowest != std::string::npos) line.replace(lowest, replacingText.length() - 1, digitMap.at(replacingText));
				}
			}
			return std::to_string(SumLines(lines));
		});
		return 0;
	}();
}
