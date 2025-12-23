#include "repositories/CommandRepository.hpp"
#include <stdexcept>

void CommandRepository::Save(std::shared_ptr<ICommand> command)
{
    m_commands[command->GetName()] = command;
}

std::shared_ptr<ICommand> CommandRepository::GetByName(const std::string &name)
{
    if (m_commands.count(name) == 0 || name.empty() == true)
        throw std::runtime_error("Can't find command '" + name + "'");

    return m_commands.at(name);
}

std::vector<std::shared_ptr<ICommand>> CommandRepository::GetAll()
{
    std::vector<std::shared_ptr<ICommand>> result;
    result.reserve(m_commands.size());

    for (const auto& [name, command] : m_commands)
    {
        result.push_back(command);
    }

    return result;
}
