#pragma once

class Library
{
public:
    void Open() { m_isOpen = true; }
    void Close() { m_isOpen = false; }
    bool IsOpen() const { return m_isOpen; }

private:
    bool m_isOpen = false;
};