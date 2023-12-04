#pragma once
namespace AOC::D3
{
	int x = []() {
		SolutionsManager::RegisterSolution("D3P1", [](std::string& input) -> std::string {
			std::vector<std::string> lines = split(input, '\n');
			for (auto& line : lines) line += '.';

			uint32_t sum = 0;
			for (int32_t i = 0; i < lines.size(); i++)
			{
				std::string& line = lines[i];
				uint32_t number = 0;
				bool isValid = false;
				for (int32_t j = 0; j < line.size(); j++)
				{
					char c = line[j];
					if (std::isdigit(c))
					{
						number *= 10;
						number += c - '0';

						for (int32_t k = -1; k <= 1; k++)
						{
							for (int32_t l = -1; l <= 1; l++)
							{
								if (k == 0 && l == 0) continue;
								if (i + k < 0 || j + l < 0 || i + k >= lines.size() || j + l >= line.size()) continue;
								char c2 = lines[i + k][j + l];
								if (!std::isdigit(c2) && c2 != '.') isValid = true;
							}
						}
					}
					else
					{
						if (number != 0)
						{
							if (isValid) sum += number;
							number = 0;
							isValid = false;
						}
					}
				}
			}

			return std::to_string(sum);
		});
		SolutionsManager::RegisterSolution("D3P2", [](std::string& input) -> std::string {
			std::vector<std::string> lines = split(input, '\n');
			for (auto& line : lines) line += '.';

			uint32_t sum = 0;
			for (int32_t i = 0; i < lines.size(); i++)
			{
				std::string& line = lines[i];
				for (int32_t j = 0; j < line.size(); j++)
				{
					char c = line[j];
					if (c == '*')
					{
						std::vector<uint32_t> foundNumbers;
						for (int32_t k = -1; k <= 1; k++)
						{
							for (int32_t l = -1; l <= 1; l++)
							{
								if (k == 0 && l == 0) continue;
								if (i + k < 0 || j + l < 0 || i + k >= lines.size() || j + l >= line.size()) continue;
								char c2 = lines[i + k][j + l];

								if (std::isdigit(c2))
								{
									// Reverse until finding the beginning of the number
									int32_t m = j + l;
									while (m >= 0 && std::isdigit(lines[i + k][m])) m--;
									m++;
									// Gather full number
									uint32_t number = 0;
									while (m < line.size() && std::isdigit(lines[i + k][m]))
									{
										number *= 10;
										number += lines[i + k][m] - '0';
										m++;
									}
									// Check if the number is already in the list
									bool alreadyFound = false;
									for (auto& foundNumber : foundNumbers)
									{
										if (foundNumber == number)
										{
										alreadyFound = true;
										break;
										}
									}
									if (!alreadyFound) foundNumbers.push_back(number);
								}
							}
						}
						if (foundNumbers.size() == 2) sum += foundNumbers[0] * foundNumbers[1];
					}
				}
			}
			return std::to_string(sum);
		});
		return 0;
	}();
}
