#pragma once

#pragma once

#include "interfaces/ICommand.hpp"
#include "repositories/CommandRepository.hpp"
#include <memory>

namespace Commands
{
    class Help : public ICommand
    {
    public:
        Help(CommandRepository &commandRepository);
        void Execute(const ParsedInput &parsedInput) override;
        std::string GetDescription() const override;
        const std::string &GetName() const override { return m_name; };

    private:
        void DisplayAllDescriptions();
        void DisplayCommandDescription(const std::string &name);

        const std::string m_name = "HELP";
        CommandRepository &m_commandRepository;
    };
}