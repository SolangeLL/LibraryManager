#pragma once

#include "models/books/ABook.hpp"

class TextBook : public ABook
{
public:
    using ABook::ABook;

    int GetMaxLoanDays() const override { return 14; }
    std::string GetType() const override { return "Manual"; }
};
