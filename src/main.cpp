#include <iostream>
#include <fmt/color.h>

#include "services/InputService.hpp"
#include "repositories/InMemoryBookRepository.hpp"
#include "repositories/CommandRepository.hpp"
#include "utils/BookFactory.hpp"
#include "utils/Logger.hpp"

#include "models/books/Novel.hpp"
#include "models/books/TextBook.hpp"
#include "models/Library.hpp"

#include "models/commands/Commands.hpp"

// TODO: Create custom exception system

void RegisterAllBookTypes(BookFactory &bookFactory)
{
     bookFactory.RegisterType<Books::Novel>("NOVEL");
     bookFactory.RegisterType<Books::TextBook>("TEXTBOOK");
}

void RegisterCommands(CommandRepository &commandRepository, BookFactory &bookFactory, std::shared_ptr<InMemoryBookRepository> &bookRepository, Library &library)
{
     commandRepository.Save(std::make_shared<Commands::Add>(bookFactory, bookRepository));
     commandRepository.Save(std::make_shared<Commands::Borrow>(bookRepository));
     commandRepository.Save(std::make_shared<Commands::Delete>(bookRepository));
     commandRepository.Save(std::make_shared<Commands::Display>(bookRepository));
     commandRepository.Save(std::make_shared<Commands::Login>(bookRepository));
     commandRepository.Save(std::make_shared<Commands::Logout>());
     commandRepository.Save(std::make_shared<Commands::Return>(bookRepository));
     commandRepository.Save(std::make_shared<Commands::Help>(commandRepository));
     commandRepository.Save(std::make_shared<Commands::Quit>(library));
}

int main(void)
{
     Logger::Init();
     Library library;
     BookFactory bookFactory;
     InputService inputService;
     CommandRepository commandRepository;
     std::shared_ptr<InMemoryBookRepository> bookRepository = std::make_shared<InMemoryBookRepository>();

     library.Open();

     RegisterAllBookTypes(bookFactory);
     RegisterCommands(commandRepository, bookFactory, bookRepository, library);

     while (library.IsOpen())
     {
          try
          {
               std::cout << "Enter a command:" << std::endl;
               ParsedInput input = inputService.GetParsedInput();
               std::shared_ptr<ICommand> command = commandRepository.GetByName(input.action);
               command->Execute(input);
          }
          catch (const std::exception &e)
          {
               LOG_ERROR("ERROR: {0}", e.what());
               // std::cerr << errorMessage << std::endl;
          }
     }

     return 0;
}