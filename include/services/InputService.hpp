#pragma once

#include <unordered_map>
#include <memory>
#include "interfaces/ICommand.hpp"

class InputService
{
    public:
        void RegisterCommand(const std::string name, ICommand &&command);
        std::shared_ptr<ICommand> ReadCommand();

    private:
        std::unordered_map<std::string, std::shared_ptr<ICommand>> m_commands;
};