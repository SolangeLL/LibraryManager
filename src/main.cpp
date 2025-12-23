#include <iostream>

#include "services/InputService.hpp"
#include "repositories/InMemoryBookRepository.hpp"
#include "utils/BookFactory.hpp"

#include "models/books/Novel.hpp"
#include "models/books/TextBook.hpp"
#include "models/Library.hpp"

#include "utils/Logger.hpp"
#include <fmt/color.h>

// TODO: Create custom exception system

int main(void)
{
     Logger::Init();
     Library library;
     std::shared_ptr<InMemoryBookRepository> bookRepository = std::make_shared<InMemoryBookRepository>();
     BookFactory bookFactory;

     LOG_INFO("Start program");

     library.Open();

     bookFactory.RegisterType<Books::Novel>("NOVEL");
     bookFactory.RegisterType<Books::TextBook>("TEXTBOOK");

     InputService inputService(bookFactory, bookRepository);

     while (library.IsOpen())
     {
          try
          {
               std::cout << "Enter a command:" << std::endl;
               inputService.ReadAndExecuteCommand();
          }
          catch (const std::exception &e)
          {
               LOG_ERROR("ERROR: {}", e.what());
          }
     }

     return 0;
}