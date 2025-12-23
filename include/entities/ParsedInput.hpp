#pragma once

#include <string>
#include <vector>

struct ParsedInput
{
    std::string action = "";
    std::string itemType = "";
    std::vector<std::string> args;
};