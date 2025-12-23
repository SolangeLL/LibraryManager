#pragma once

#include "interfaces/ICommand.hpp"
#include "interfaces/IBookRepository.hpp"
#include <memory>

namespace Commands
{
    class Login : public ICommand
    {
    public:
        Login(std::shared_ptr<IBookRepository> bookRepository);
        void Execute(const ParsedInput &parsedInput) override;
        std::string GetDescription() const override;
        const std::string &GetName() const override { return m_name; };

    private:
        std::shared_ptr<IBookRepository> m_bookRepository;
        const std::string m_name = "LOGIN";
    };
}