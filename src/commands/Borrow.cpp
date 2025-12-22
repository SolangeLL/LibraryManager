#include "models/commands/Borrow.hpp"

namespace Commands
{
    Borrow::Borrow(std::shared_ptr<IBookRepository> bookRepository) : m_bookRepository(bookRepository) {}


    void Borrow::Execute(const ParsedCommand &command)
    {
        std::cout << "Execute BORROW command" << std::endl;
    }
}