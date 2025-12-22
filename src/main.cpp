#include <iostream>

#include "services/InputService.hpp"
#include "repositories/InMemoryBookRepository.hpp"
#include "utils/BookFactory.hpp"

#include "models/books/Novel.hpp"
#include "models/books/TextBook.hpp"
#include <fmt/color.h>

// TODO: Create custom exception system

int main(void)
{
     std::shared_ptr<InMemoryBookRepository> bookRepository = std::make_shared<InMemoryBookRepository>();
     BookFactory bookFactory;

     bookFactory.RegisterType<Books::Novel>("NOVEL");
     bookFactory.RegisterType<Books::TextBook>("TEXTBOOK");

     InputService inputService(bookFactory, bookRepository);

     while (true)
     {
          try
          {
               std::cout << "Enter a command:" << std::endl;
               inputService.ReadAndExecuteCommand();
          }
          catch (const std::exception &e)
          {
               std::cerr << fmt::format(fg(fmt::color::red), "ERROR: {}", e.what()) << '\n';
          }
     }

     return 0;
}