#pragma once

#include <string>

class IBorrowable
{
public:
    virtual ~IBorrowable() = default;
    virtual bool IsAvailable() const = 0;
    virtual std::string GetId() const = 0;
    virtual std::string GetTitle() const = 0;
};
