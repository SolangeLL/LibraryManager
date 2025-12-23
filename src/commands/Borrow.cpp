#include "models/commands/Borrow.hpp"
#include "utils/Logger.hpp"

namespace Commands
{
    Borrow::Borrow(std::shared_ptr<IBookRepository> bookRepository) : m_bookRepository(bookRepository) {}

    void Borrow::Execute(const ParsedInput &parsedInput)
    {
        try
        {
            std::shared_ptr<IBook> book = m_bookRepository->GetById(parsedInput.option);

            if (IsBookAlreadyBorrowed(book))
                return;

            book->Borrow();
            LOG_INFO("Book {0} has been successfully borrowed.", book->GetTitle());
        }
        catch (const std::exception &e)
        {
            LOG_ERROR("{}", e.what());
        }
    }

    std::string Borrow::GetDescription() const
    {
        std::string description = "";
        description += m_name + " <item_id>";
        description += "\tBorrow item type. Set item to unavailable.";
        return description;
    }

    bool Borrow::IsBookAlreadyBorrowed(std::shared_ptr<IBook> book) const
    {
        if (book->IsAvailable() == false)
        {
            LOG_WARN("Book {0} has been already borrowed by someone else.", book->GetTitle());
            return true;
        }

        return false;
    }
}