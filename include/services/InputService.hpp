#pragma once

#include <unordered_map>
#include <memory>
#include "interfaces/ICommand.hpp"
#include "interfaces/IBookRepository.hpp"
#include "utils/BookFactory.hpp"

class InputService
{
    public:
        InputService(BookFactory& bookFactory, std::shared_ptr<IBookRepository> bookRepository);
        void ReadAndExecuteCommand();

    private:
        void RegisterCommands();
        void ConvertStringToUppercase(std::string &string);
        ParsedInput GetParsedInput();

        std::unordered_map<std::string, std::shared_ptr<ICommand>> m_commands;
        BookFactory& m_bookFactory;
        std::shared_ptr<IBookRepository> m_bookRepository;

};