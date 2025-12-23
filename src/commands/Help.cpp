#include "models/commands/Help.hpp"
#include "utils/Logger.hpp"
#include <fmt/color.h>

namespace Commands
{
    Help::Help(CommandRepository &commandRepository) : m_commandRepository(commandRepository) {}

    void Help::Execute(const ParsedInput &parsedInput)
    {
        if (parsedInput.itemType.empty() == true)
        {
            DisplayAllDescriptions();
            return;
        }

        DisplayCommandDescription(parsedInput.itemType);
    }

    std::string Help::GetDescription() const
    {
        std::string description = "";
        description += m_name;
        description += "\tDisplay all available commands.";
        return description;
    }

    void Help::DisplayAllDescriptions()
    {
        std::cout << "========== COMMANDS ==========" << std::endl;

        std::vector<std::shared_ptr<ICommand>> commands = m_commandRepository.GetAll();
        for (const auto &command : commands)
        {
            std::cout << command->GetDescription() << std::endl;
        }
    }

    void Help::DisplayCommandDescription(const std::string &name)
    {
        try
        {
            std::shared_ptr<ICommand> command = m_commandRepository.GetByName(name);
            std::string italicName = fmt::format(fmt::emphasis::italic, "{}", name);
            std::cout << "========== USAGE OF COMMAND " + italicName + " ==========" << std::endl;
            std::cout << command->GetDescription() << std::endl;
        }
        catch (const std::exception &e)
        {
            LOG_ERROR("{}", e.what());
        }
    }
}