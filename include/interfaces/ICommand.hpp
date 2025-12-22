#pragma once

#include <vector>
#include <string>
#include "types/ParsedCommand.hpp"

#include <iostream>
class ICommand
{
public:
    virtual ~ICommand() = default;
    virtual void Execute(const ParsedCommand &command) = 0;
};