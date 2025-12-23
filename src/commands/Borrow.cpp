#include "models/commands/Borrow.hpp"

namespace Commands
{
    Borrow::Borrow(std::shared_ptr<IBookRepository> bookRepository) : m_bookRepository(bookRepository) {}


    void Borrow::Execute(const ParsedInput &parsedInput)
    {
        std::cout << "Execute BORROW command" << std::endl;
    }

    std::string Borrow::GetDescription() const
    {
        std::string description = "";
        description += m_name;
        description += "\tBorrow item type. Set item to unavailable.";
        return description;
    }
}