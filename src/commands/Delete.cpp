#include "models/commands/Delete.hpp"

namespace Commands
{
    Delete::Delete(std::shared_ptr<IBookRepository> bookRepository) : m_bookRepository(bookRepository) {}

    void Delete::Execute(const ParsedInput &parsedInput)
    {
        std::cout << "Execute DELETE command" << std::endl;
    }

    std::string Delete::GetDescription() const
    {
        std::string description = "";
        description += m_name;
        description += "\tDelete item.";
        return description;
    }
}