#pragma once

#include <string>
#include <vector>

struct ParsedInput
{
    std::string action = "";
    std::string option = "";
    std::vector<std::string> args;
};