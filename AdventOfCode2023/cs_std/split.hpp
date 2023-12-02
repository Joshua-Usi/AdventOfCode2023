#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

namespace cs_std
{
    std::vector<std::string> split(const std::string& str, char delim) {
        std::vector<std::string> tokens;
        std::string token;
        for (char ch : str)
        {
            if (ch == '\0') continue;
            if (ch != delim)
            {
                token += ch;
            }
            else
            {
                if (!token.empty())
                {
                    tokens.push_back(token);
                    token.clear();
                }
            }
        }
        if (!token.empty()) tokens.push_back(token);
        return tokens;
    }
}