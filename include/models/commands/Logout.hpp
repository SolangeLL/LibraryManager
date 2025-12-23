#pragma once

#include "interfaces/ICommand.hpp"
#include "interfaces/IBookRepository.hpp"
#include <memory>

namespace Commands
{
    class Logout : public ICommand
    {
    public:
        void Execute(const ParsedInput &parsedInput) override;
        std::string GetDescription() const override;
        const std::string &GetName() const override { return m_name; };

    private:
        const std::string m_name = "LOGOUT";
    };
}