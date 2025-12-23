#pragma once

#pragma once

#include "models/Library.hpp"
#include "interfaces/ICommand.hpp"

namespace Commands
{
    class Quit : public ICommand
    {
    public:
        Quit(Library &library);
        void Execute(const ParsedInput &parsedInput) override;
        std::string GetDescription() const override;
        const std::string &GetName() const override { return m_name; };

    private:
        const std::string m_name = "QUIT";
        Library &m_library;
    };
}