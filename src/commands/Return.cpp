#include "models/commands/Return.hpp"

namespace Commands
{
    Return::Return(std::shared_ptr<IBookRepository> bookRepository) : m_bookRepository(bookRepository) {}

    void Return::Execute(const ParsedInput &parsedInput)
    {
        std::cout << "Execute RETURN command" << std::endl;
    }

    std::string Return::GetDescription() const
    {
        std::string description = "";
        description += m_name;
        description += "\tReturn item type. Set item to available.";
        return description;
    }
}