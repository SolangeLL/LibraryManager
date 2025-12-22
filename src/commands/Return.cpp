#include "models/commands/Return.hpp"

namespace Commands
{
    Return::Return(std::shared_ptr<IBookRepository> bookRepository) : m_bookRepository(bookRepository) {}

    void Return::Execute(const ParsedInput &parsedInput)
    {
        std::cout << "Execute RETURN command" << std::endl;
    }
}