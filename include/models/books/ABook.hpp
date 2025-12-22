#pragma once

#include "interfaces/IBook.hpp"

class ABook : public IBook
{
public:
    ABook(const std::string &id, const std::string &title, const std::string &author)
        : m_id(id), m_title(title), m_author(author) {}

    bool IsAvailable() const override { return m_available; }
    const std::string &GetId() const override { return m_id; }
    std::string GetTitle() const override { return m_title; }
    std::string GetAuthor() const override { return m_author; }

    void SetAvailable(bool status) { m_available = status; }

protected:
    std::string m_id;
    std::string m_title;
    std::string m_author;
    bool m_available = true;
};