#pragma once

#include "domain/entities/books/ABook.hpp"

class Novel : public ABook {
public:
    Novel(const std::string& id, const std::string& title, const std::string& author)
        : ABook(id, title, author) {}

    int GetMaxLoanDays() const override { return 21; }
    std::string GetType() const override { return "Novel"; }
};