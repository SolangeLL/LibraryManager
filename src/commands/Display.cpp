#include "models/commands/Display.hpp"
#include <fmt/core.h>
#include <fmt/color.h>

namespace Commands
{
    Display::Display(std::shared_ptr<IBookRepository> bookRepository) : m_bookRepository(bookRepository) {}

    void Display::Execute(const ParsedInput &parsedInput)
    {
        std::cout << "========== BOOK INVENTORY ==========" << std::endl;
        for (auto &book : m_bookRepository->GetAll())
        {
            std::string phrase;
            auto availabilityColor = book->IsAvailable() ? bg(fmt::color::green) : bg(fmt::color::red);
            phrase += fmt::format(availabilityColor, "[ ]");
            phrase += fmt::format(fmt::emphasis::italic, " {} ", book->GetTitle());
            phrase += "written by " + fmt::format(fmt::emphasis::italic, "{} ", book->GetAuthor());
            phrase += "contains " + fmt::format(fmt::emphasis::bold, "{} ", book->GetNumberPages()) + "pages ";
            phrase += "(id#" + fmt::format(fmt::emphasis::italic, "{}", book->GetId()) + ")";
            std::cout << phrase << std::endl;
        }
    }
}