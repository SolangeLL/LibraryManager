#pragma once

#include "domain/entities/books/ABook.hpp"
#include "domain/entities/users/AUser.hpp"
#include <memory>
#include <chrono>
#include <vector>

// TODO: Maybe create Date class to handle diff time checks ?
using Date = std::chrono::system_clock::time_point;

class Loan
{
public:
    Loan(const std::string &id, std::shared_ptr<AUser> user, std::shared_ptr<ABook> book, Date loan, Date due)
        : m_loanId(id), m_user(user), m_book(book), m_loanDate(loan), m_dueDate(due), m_returned(false) {}

    std::string GetId() const { return m_loanId; }
    std::shared_ptr<AUser> GetUser() const { return m_user; }
    std::shared_ptr<ABook> GetBook() const { return m_book; }
    Date GetDueDate() const { return m_dueDate; }
    bool IsReturned() const { return m_returned; }

    void MarkAsReturned() { m_returned = true; }

    int GetDaysOverdue() const
    {
        if (m_returned)
            return 0;

        auto now = std::chrono::system_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::hours>(now - m_dueDate).count() / 24;
        return std::max(0, static_cast<int>(diff));
    }

    double CalculateLatePenalty() const
    {
        return GetDaysOverdue() * m_user->GetPenaltyRate();
    }

private:
    std::string m_loanId;
    std::shared_ptr<AUser> m_user;
    std::shared_ptr<ABook> m_book;
    Date m_loanDate;
    Date m_dueDate;
    bool m_returned;
};