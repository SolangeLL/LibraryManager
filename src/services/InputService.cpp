#include "services/InputService.hpp"
#include "utils/InputParser.hpp"
#include <algorithm>
#include <iostream>

void InputService::ConvertStringToUppercase(std::string &string)
{
    std::transform(string.begin(), string.end(), string.begin(), ::toupper);
}

ParsedInput InputService::GetParsedInput()
{
    std::string rawCommand;
    std::getline(std::cin, rawCommand);
    ParsedInput command = InputParser::Parse(rawCommand);

    ConvertStringToUppercase(command.action);
    ConvertStringToUppercase(command.itemType);

    return command;
}