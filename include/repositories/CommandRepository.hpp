#pragma once

#include <unordered_map>
#include "interfaces/ICommandRepository.hpp"

class CommandRepository : public ICommandRepository
{
public:
    void Save(std::shared_ptr<ICommand> command) override;
    std::shared_ptr<ICommand> GetByName(const std::string &name) override;
    std::vector<std::shared_ptr<ICommand>> GetAll() override;

private:
    std::unordered_map<std::string, std::shared_ptr<ICommand>> m_commands;
};