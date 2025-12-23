#pragma once

#include <vector>
#include <string>
#include "entities/ParsedInput.hpp"

#include <iostream>
class ICommand
{
public:
    virtual ~ICommand() = default;
    virtual void Execute(const ParsedInput &parsedInput) = 0;
};