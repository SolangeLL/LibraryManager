#pragma once

#include "interfaces/ICommand.hpp"
#include "interfaces/IBookRepository.hpp"
#include <memory>

namespace Commands
{
    class Display : public ICommand
    {
    public:
        Display(std::shared_ptr<IBookRepository> bookRepository);
        void Execute(const ParsedInput &parsedInput) override;

    private:
        std::shared_ptr<IBookRepository> m_bookRepository;
    };
}