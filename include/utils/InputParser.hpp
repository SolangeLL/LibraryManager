#pragma once

#include <stdexcept>
#include "types/ParsedCommand.hpp"

class InputParser
{
public:
    static ParsedCommand Parse(const std::string &input)
    {
        ParsedCommand result;
        std::vector<std::string> tokens = Tokenize(input);

        if (tokens.empty())
        {
            throw std::runtime_error("Empty command");
        }

        result.action = tokens[0];

        if (tokens.size() > 1)
        {
            result.itemType = tokens[1];
        }

        if (tokens.size() > 2)
        {
            result.args = std::vector<std::string>(tokens.begin() + 2, tokens.end());
        }

        return result;
    }

private:
    static std::vector<std::string> Tokenize(const std::string &input)
    {
        std::vector<std::string> tokens;
        std::string current;
        bool inQuotes = false;

        for (char c : input)
        {
            if (c == '"')
            {
                inQuotes = !inQuotes;
            }
            else if (c == ' ' && !inQuotes)
            {
                if (!current.empty())
                {
                    tokens.push_back(current);
                    current.clear();
                }
            }
            else
            {
                current += c;
            }
        }

        if (!current.empty())
        {
            tokens.push_back(current);
        }

        return tokens;
    }
};
