#include "models/commands/Add.hpp"
#include <fmt/color.h>

namespace Commands
{
    Add::Add(BookFactory& bookFactory, std::shared_ptr<IBookRepository> bookRepository)
    : m_bookFactory(bookFactory), m_bookRepository(bookRepository) {}

    void Add::Execute(const ParsedInput &parsedInput)
    {
        if (parsedInput.itemType.empty() == true)
            throw std::invalid_argument("No type has been given");

        if (parsedInput.args.empty() == true)
            throw std::invalid_argument("No args has been given");

        auto newBook = m_bookFactory.Create(parsedInput.itemType, parsedInput.args);
        m_bookRepository->Save(newBook);

        fmt::print(fg(fmt::color::green), "Item {} successfully added!\n", parsedInput.itemType);
    }
}