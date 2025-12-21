#pragma once

#include "models/books/ABook.hpp"

class Novel : public ABook {
public:
    using ABook::ABook;

    int GetMaxLoanDays() const override { return 21; }
    std::string GetType() const override { return "Novel"; }
};