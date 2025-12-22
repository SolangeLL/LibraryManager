#include "models/commands/Add.hpp"

namespace Commands
{
    Add::Add(std::shared_ptr<IBookRepository> bookRepository) : m_bookRepository(bookRepository) {}

    void Add::Execute(const ParsedCommand &command)
    {
        std::cout << "Action: " << command.action << std::endl;
        std::cout << "type: " << command.itemType << std::endl;
        std::cout << "args: " << std::endl;
        for (auto &arg : command.args)
            std::cout << "- " << arg << std::endl;

        if (command.itemType.empty() == true)
            throw std::invalid_argument("No type has been given");

        std::cout << "Execute ADD command" << std::endl;
    }
}