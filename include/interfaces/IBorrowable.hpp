#pragma once

#include <string>

class IBorrowable
{
public:
    virtual ~IBorrowable() = default;
    virtual bool IsAvailable() const = 0;
    virtual const std::string& GetId() const = 0;
    virtual void Borrow() = 0;
    virtual void Return() = 0;
};
