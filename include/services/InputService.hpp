#pragma once

#include <unordered_map>
#include <memory>
#include "interfaces/ICommand.hpp"
#include "interfaces/IBookRepository.hpp"

class InputService
{
    public:
        InputService(std::shared_ptr<IBookRepository> bookRepository);
        void ReadAndExecuteCommand();

    private:
        void RegisterCommands();
        void ConvertStringToUppercase(std::string &string);
        ParsedCommand GetParsedCommand();

        std::unordered_map<std::string, std::shared_ptr<ICommand>> m_commands;
        std::shared_ptr<IBookRepository> m_bookRepository;

};