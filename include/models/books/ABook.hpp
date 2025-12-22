#pragma once

#include "interfaces/IBook.hpp"
#include <vector>
#include <stdexcept>

class ABook : public IBook
{
public:
    ABook(const std::vector<std::string> &arguments)
    {
        static int id = 0;

        if (arguments.size() != 3)
            throw std::invalid_argument("Usage: ADD <book_type> <title> <author> <number_pages>");

        m_id = std::to_string(id++);
        m_title = arguments[TITLE];
        m_author = arguments[AUTHOR];
        m_numberPages = std::stoi(arguments[NUMBER_PAGES]);
    }

    bool IsAvailable() const override { return m_available; }
    int GetNumberPages() const override { return m_numberPages; }
    const std::string &GetId() const override { return m_id; }
    std::string GetTitle() const override { return m_title; }
    std::string GetAuthor() const override { return m_author; }

    void Borrow() override { m_available = false; }
    void Return() override { m_available = true; }

protected:
    enum PropertyIndex
    {
        TITLE,
        AUTHOR,
        NUMBER_PAGES
    };

    std::string m_id;
    std::string m_title;
    std::string m_author;
    int m_numberPages;
    bool m_available = true;
};