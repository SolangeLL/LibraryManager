#include "repositories/InMemoryBookRepository.hpp"

void InMemoryBookRepository::Save(std::shared_ptr<IBook> data)
{
    static int index = 0;

    m_books.insert({std::to_string(index++), data});
}

std::shared_ptr<IBook> InMemoryBookRepository::GetById(const std::string &id)
{
    if (m_books.count(id) == 0)
        throw std::runtime_error("InMemoryBookRepository does not have book id '" + id + "'");
    return m_books.at(id);
}

std::vector<std::shared_ptr<IBook>> InMemoryBookRepository::GetAll()
{
    std::vector<std::shared_ptr<IBook>> allBooks;
    allBooks.reserve(m_books.size());

    for (const auto &[key, book] : m_books)
    {
        allBooks.push_back(book);
    }

    return allBooks;
}

void InMemoryBookRepository::DeleteById(const std::string &id)
{
    if (m_books.count(id) == 0)
        throw std::invalid_argument("No book with id '" + id + "' was found.");

    m_books.erase(id);
}
