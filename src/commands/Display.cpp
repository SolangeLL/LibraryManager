#include "models/commands/Display.hpp"

namespace Commands
{
    Display::Display(std::shared_ptr<IBookRepository> bookRepository) : m_bookRepository(bookRepository) {}

    void Display::Execute(const ParsedCommand &command)
    {
        std::cout << "Execute DISPLAY command" << std::endl;
    }
}