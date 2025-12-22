#pragma once

#include "interfaces/ICommand.hpp"
#include "interfaces/IBookRepository.hpp"
#include <memory>

namespace Commands
{
    class Borrow : public ICommand
    {
    public:
        Borrow(std::shared_ptr<IBookRepository> bookRepository);
        void Execute(const ParsedCommand &command) override;

    private:
        std::shared_ptr<IBookRepository> m_bookRepository;
    };
}