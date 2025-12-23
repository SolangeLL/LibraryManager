#include "models/commands/Login.hpp"

namespace Commands
{
    Login::Login(std::shared_ptr<IBookRepository> bookRepository) : m_bookRepository(bookRepository) {}

    void Login::Execute(const ParsedInput &parsedInput)
    {
        std::cout << "Execute LOGIN command" << std::endl;
    }

    std::string Login::GetDescription() const
    {
        std::string description = "";
        description += m_name;
        description += "\tLogin a user.";
        return description;
    }
}