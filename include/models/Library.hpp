#pragma once

class Library
{
public:
    void Open();
    void Close();
    bool IsOpen() const;

private:
    bool m_isOpen = false;
};