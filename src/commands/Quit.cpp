#include "models/commands/Quit.hpp"

namespace Commands
{
    Quit::Quit(Library &library) : m_library(library) {}

    void Quit::Execute(const ParsedInput &parsedInput)
    {
        m_library.Close();
    }

    std::string Quit::GetDescription() const
    {
        std::string description = "";
        description += m_name;
        description += "\tQuit the library manager program.";
        return description;
    }
}