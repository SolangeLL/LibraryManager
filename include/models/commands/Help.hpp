#pragma once

#pragma once

#include "interfaces/ICommand.hpp"
#include "interfaces/IBookRepository.hpp"
#include <memory>

namespace Commands
{
    class Help : public ICommand
    {
    public:
        void Execute(const ParsedInput &parsedInput) override;
    };
}