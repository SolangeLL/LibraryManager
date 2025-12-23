#pragma once

#include <memory>
#include <vector>
#include "ICommand.hpp"

class ICommandRepository
{
public:
    virtual ~ICommandRepository() = default;
    virtual void Save(std::shared_ptr<ICommand> command) = 0;
    virtual std::shared_ptr<ICommand> GetByName(const std::string &name) = 0;
    virtual std::vector<std::shared_ptr<ICommand>> GetAll() = 0;
};