#pragma once

#include "domain/entities/books/ABook.hpp"

class TextBook : public ABook
{
public:
    TextBook(const std::string &id, const std::string &title, const std::string &author)
        : ABook(id, title, author) {}

    int GetMaxLoanDays() const override { return 14; }
    std::string GetType() const override { return "Manual"; }
};