#pragma once

#include "entities/ParsedInput.hpp"

class InputService
{
    public:
        ParsedInput GetParsedInput();

    private:
        void ConvertStringToUppercase(std::string &string);
};