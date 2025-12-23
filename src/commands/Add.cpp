#include "models/commands/Add.hpp"
#include <fmt/color.h>

namespace Commands
{
    Add::Add(BookFactory& bookFactory, std::shared_ptr<IBookRepository> bookRepository)
    : m_bookFactory(bookFactory), m_bookRepository(bookRepository) {}

    void Add::Execute(const ParsedInput &parsedInput)
    {
        if (parsedInput.option.empty() == true)
            throw std::invalid_argument("No type has been given");

        if (parsedInput.args.empty() == true)
            throw std::invalid_argument("No args has been given");

        auto newBook = m_bookFactory.Create(parsedInput.option, parsedInput.args);
        m_bookRepository->Save(newBook);

        fmt::print(fg(fmt::color::green), "Item {} successfully added!\n", parsedInput.option);
    }

    std::string Add::GetDescription() const
    {
        std::string description = "";
        description += m_name + " <book_type> <title> <author> <number_pages>\n";
        description += "\tAdd a new book in data base.\n";
        description += "\t<book_type>: NOVEL, TEXTBOOK\n";
        description += "\t<title>: Title, \"Longer title\"\n";
        description += "\t<author>: Buddy, \"Victor Hugo\"\n";
        description += "\t<number_pages>: 1, 1500";
        return description;
    }
}