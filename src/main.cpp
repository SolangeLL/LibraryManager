// #include "models/books/Novel.hpp"
// #include "models/books/TextBook.hpp"
// #include "models/users/Student.hpp"
// #include "models/users/Professor.hpp"
// #include "services/LoanService.hpp"
// #include "services/notifications/EmailNotificationService.hpp"

#include <iostream>

#include "services/InputService.hpp"
#include "repositories/InMemoryBookRepository.hpp"

// TODO: Create custom exception system

int main(void)
{
     std::shared_ptr<InMemoryBookRepository> bookRepository = std::make_shared<InMemoryBookRepository>();
     InputService inputService(bookRepository);

     while (true)
     {
          try
          {
               std::cout << "Enter a command:" << std::endl;
               inputService.ReadAndExecuteCommand();
          }
          catch (const std::exception &e)
          {
               std::cerr << e.what() << '\n';
          }
     }

     return 0;
}