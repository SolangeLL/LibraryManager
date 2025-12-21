#pragma once

class ICommand
{
public:
    virtual ~ICommand() = default;
    virtual void Exectute() = 0;
};