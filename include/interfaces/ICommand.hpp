#pragma once

#include <vector>
#include <string>
#include "types/ParsedInput.hpp"

#include <iostream>
class ICommand
{
public:
    virtual ~ICommand() = default;
    virtual void Execute(const ParsedInput &parsedInput) = 0;
};