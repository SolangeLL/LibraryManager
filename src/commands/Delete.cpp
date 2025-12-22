#include "models/commands/Delete.hpp"

namespace Commands
{
    Delete::Delete(std::shared_ptr<IBookRepository> bookRepository) : m_bookRepository(bookRepository) {}

    void Delete::Execute(const ParsedCommand &command)
    {
        std::cout << "Execute DELETE command" << std::endl;
    }
}