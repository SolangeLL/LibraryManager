#pragma once

#include <string>
#include <vector>

struct ParsedCommand
{
    std::string action = "";
    std::string itemType = "";
    std::vector<std::string> args;
};