#include "models/commands/Delete.hpp"

namespace Commands
{
    Delete::Delete(std::shared_ptr<IBookRepository> bookRepository) : m_bookRepository(bookRepository) {}

    void Delete::Execute(const ParsedInput &parsedInput)
    {
        std::cout << "Execute DELETE command" << std::endl;
    }
}