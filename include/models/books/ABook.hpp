#pragma once

#include "interfaces/IBorrowable.hpp"

class ABook : public IBorrowable
{
public:
    ABook(const std::string &id, const std::string &title, const std::string &author)
        : m_id(id), m_title(title), m_author(author) {}

    bool IsAvailable() const override { return m_available; }
    std::string GetId() const override { return m_id; }
    std::string GetTitle() const override { return m_title; }
    std::string GetAuthor() const { return m_author; }

    void SetAvailable(bool status) { m_available = status; }

    virtual int GetMaxLoanDays() const = 0;
    virtual std::string GetType() const = 0;

protected:
    std::string m_id;
    std::string m_title;
    std::string m_author;
    bool m_available = true;
};