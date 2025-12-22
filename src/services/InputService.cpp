#include "services/InputService.hpp"
#include "models/commands/Commands.hpp"
#include "utils/InputParser.hpp"
#include <iostream>
#include <algorithm>

InputService::InputService(std::shared_ptr<IBookRepository> bookRepository) : m_bookRepository(bookRepository)
{
    RegisterCommands();
}

void InputService::ReadAndExecuteCommand()
{
    ParsedCommand command = GetParsedCommand();
    m_commands[command.action]->Execute(command);
}

void InputService::ConvertStringToUppercase(std::string &string)
{
    std::transform(string.begin(), string.end(), string.begin(), ::toupper);
}

void InputService::RegisterCommands()
{
    m_commands["ADD"] = std::make_shared<Commands::Add>(m_bookRepository);
    m_commands["BORROW"] = std::make_shared<Commands::Borrow>(m_bookRepository);
    m_commands["DELETE"] = std::make_shared<Commands::Delete>(m_bookRepository);
    m_commands["DISPLAY"] = std::make_shared<Commands::Display>(m_bookRepository);
    m_commands["LOGIN"] = std::make_shared<Commands::Login>(m_bookRepository);
    m_commands["RETURN"] = std::make_shared<Commands::Return>(m_bookRepository);
}

ParsedCommand InputService::GetParsedCommand()
{
    std::string rawCommand;
    std::getline(std::cin, rawCommand);
    ParsedCommand command = InputParser::Parse(rawCommand);

    ConvertStringToUppercase(command.action);

    if (m_commands.count(command.action) == 0)
        throw std::invalid_argument("Unkown command '" + command.action + "'");

    return command;
}