#pragma once

#include "interfaces/ICommand.hpp"
#include "interfaces/IBookRepository.hpp"
#include "utils/BookFactory.hpp"
#include <memory>

namespace Commands
{
    class Add : public ICommand
    {
    public:
        Add(BookFactory& bookFactory, std::shared_ptr<IBookRepository> bookRepository);
        void Execute(const ParsedInput &parsedInput) override;
        std::string GetDescription() const override;
        const std::string &GetName() const override { return m_name; };

    private:
        BookFactory &m_bookFactory;
        std::shared_ptr<IBookRepository> m_bookRepository;
        const std::string m_name = "ADD";
    };
}