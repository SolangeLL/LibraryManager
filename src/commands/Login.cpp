#include "models/commands/Login.hpp"

namespace Commands
{
    Login::Login(std::shared_ptr<IBookRepository> bookRepository) : m_bookRepository(bookRepository) {}

    void Login::Execute(const ParsedCommand &command)
    {
        std::cout << "Execute LOGIN command" << std::endl;
    }
}