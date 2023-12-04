#pragma once

#include <string>

namespace cs_std
{
	std::string replace(const std::string& str, const std::string& delimiter, const std::string& replacement)
	{
		std::string result = str;
		size_t pos = 0;
		while ((pos = result.find(delimiter, pos)) != std::string::npos)
		{
			result.replace(pos, delimiter.length(), replacement);
			pos += replacement.length();
		}
		result.erase(std::remove(result.begin(), result.end(), '\0'), result.end());
		return result;
	}
}