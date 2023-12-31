#pragma once

#include <array>
#include <unordered_map>
#include <functional>
#include <unordered_set>

#include "console.hpp"
#include "file.hpp"
#include "split.hpp"
#include "replace.hpp"

class SolutionsManager
{
public:
	typedef std::function<std::string(std::string&)> Function;
private:
	inline static std::unordered_map<std::string, Function> solutions {};
public:
	static void Register(const std::string& name, const Function& function) { solutions[name] = function; }
	static int Run(bool useExamples = false)
	{
		for (uint32_t i = 1; i <= 25; i++)
		{
			for (uint32_t j = 1; j <= 2; j++)
			{
				const std::string name = "D" + std::to_string(i) + "P" + std::to_string(j);
				if (solutions.find(name) != solutions.end())
				{
					const std::filesystem::path path = "./Inputs/D" + std::to_string(i) + ((useExamples) ? "P" + std::to_string(j) + "Example" : "") + ".txt";

					if (!std::filesystem::exists(path))
					{
						cs_std::console::log("Input file for", name, "not found.");
						continue;
					}
					std::string input = cs_std::text_file(path).open().read();
					cs_std::console::log(name + ":", solutions[name](input));
				}
			}
		}
		return 0;
	}
	static void GenerateDays()
	{
		std::string tp = cs_std::text_file("./Solutions/template.hpp").open().read();
		for (uint32_t i = 1; i <= 25; i++)
		{
			cs_std::text_file file("./Solutions/D" + std::to_string(i) + ".hpp");
			if (file.exists()) continue;

			std::string day(tp);
			day = cs_std::replace(day, "DAY_NAME", "D" + std::to_string(i));

			file.create();
			file.open().append(day).close();
		}
	}
};