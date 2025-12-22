#pragma once

#include "interfaces/IBorrowable.hpp"

class IBook : public IBorrowable
{
public:
    virtual ~IBook() = default;
    virtual int GetMaxLoanDays() const = 0;
    virtual int GetNumberPages() const = 0;
    virtual std::string GetTitle() const = 0;
    virtual std::string GetAuthor() const = 0;
    virtual std::string GetType() const = 0;
};