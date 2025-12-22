#include "models/commands/Help.hpp"

namespace Commands
{
    void Help::Execute(const ParsedInput &parsedInput)
    {
        std::cout << "========== COMMANDS ==========" << std::endl;
        std::cout << "ADD <book_type> <title> <author> <number_pages>" << std::endl;
        std::cout << "\tAdd a new book in data base." << std::endl;
        std::cout << "\t<book_type>: NOVEL, TEXTBOOK" << std::endl;
        std::cout << "\t<title>: Title, \"Longer title\"" << std::endl;
        std::cout << "\t<author>: Buddy, \"Victor Hugo\"" << std::endl;
        std::cout << "\t<number_pages>: 1, 1500" << std::endl;
        std::cout << "DISPLAY " << std::endl;
        std::cout << "\tDisplay all books from data base." << std::endl;
    }
}