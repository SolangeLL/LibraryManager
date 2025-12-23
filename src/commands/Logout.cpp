#include "models/commands/Logout.hpp"

namespace Commands
{
    void Logout::Execute(const ParsedInput &parsedInput)
    {
        std::cout << "Execute LOGOUT command" << std::endl;
    }

    std::string Logout::GetDescription() const
    {
        std::string description = "";
        description += m_name;
        description += "\tLogout a user.";
        return description;
    }
}