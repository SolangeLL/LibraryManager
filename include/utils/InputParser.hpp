#pragma once

#include <stdexcept>
#include "entities/ParsedInput.hpp"

class InputParser
{
public:
    static ParsedInput Parse(const std::string &input);

private:
    static std::vector<std::string> Tokenize(const std::string &input);
};
