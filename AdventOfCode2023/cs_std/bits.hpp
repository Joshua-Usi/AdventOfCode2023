#pragma once

#include <array>
#include <unordered_map>
#include <functional>

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
	static void RegisterSolution(const std::string& name, const Function& function) { solutions[name] = function; }
	static void Run()
	{
		for (uint32_t i = 1; i <= 25; i++)
		{
			for (uint32_t j = 1; j <= 2; j++)
			{
				const std::string name = "D" + std::to_string(i) + "P" + std::to_string(j);
				if (solutions.find(name) != solutions.end())
				{
					const std::filesystem::path path = "./Inputs/D" + std::to_string(i) + ".txt";
					std::string input = cs_std::text_file(path).open().read_if_exists();
					cs_std::console::log(name + ":", solutions[name](input));
				}
			}
		}
	}
};