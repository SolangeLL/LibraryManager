#include "models/commands/Return.hpp"
#include <utils/Logger.hpp>

namespace Commands
{
    Return::Return(std::shared_ptr<IBookRepository> bookRepository) : m_bookRepository(bookRepository) {}

    void Return::Execute(const ParsedInput &parsedInput)
    {
        try
        {
            std::shared_ptr<IBook> book = m_bookRepository->GetById(parsedInput.option);

            if (IsBookAlreadyReturned(book))
                return;

            book->Return();
            LOG_INFO("Book {0} has been successfully returned.", book->GetTitle());
        }
        catch (const std::exception &e)
        {
            LOG_ERROR("{}", e.what());
        }
    }

    std::string Return::GetDescription() const
    {
        std::string description = "";
        description += m_name;
        description += "\tReturn item type. Set item to available.";
        return description;
    }

    bool Return::IsBookAlreadyReturned(std::shared_ptr<IBook> book) const
    {
        if (book->IsAvailable() == true)
        {
            LOG_WARN("Book {0} already returned.", book->GetTitle());
            return true;
        }

        return false;
    }
}