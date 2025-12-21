#include "models/books/Novel.hpp"
#include "models/books/TextBook.hpp"
#include "models/users/Student.hpp"
#include "models/users/Professor.hpp"
#include "services/LoanService.hpp"
#include "services/notifications/EmailNotificationService.hpp"

#include <iostream>

#include "services/InputService.hpp"

// TODO: Create custom exception system

int main(void)
{
    //  InputService inputService;

    //  inputService.RegisterCommand()

    std::cout << "=== Library Management System ===\n\n";
    std::cout << "\\\\ Test Prints //\n";

    std::shared_ptr<INotificationService> emailService = std::make_shared<EmailNotificationService>();

    LoanService loanService(emailService);

    auto book1 = std::make_shared<Novel>("B001", "The Lord of the Rings", "J.R.R. Tolkien");
    auto book2 = std::make_shared<TextBook>("B002", "Clean Code", "Robert C. Martin");

    auto student = std::make_shared<Student>("U001", "Jane Doe", "jane.doe@email.com");
    auto professor = std::make_shared<Professor>("U002", "John Doe", "john.doe@email.com");

    std::cout << "\n--- Creating Loans ---\n";
    loanService.CreateLoan(student, book1);
    loanService.CreateLoan(professor, book2);

    std::cout << "\n--- Attempting to loan an unavailable book ---\n";
    loanService.CreateLoan(student, book1);

    std::cout << "\n--- Information ---\n";
    std::cout << "Active loans for " << student->GetName() << ": "
         << loanService.CountActiveLoans(student) << "/" << student->GetMaxLoans() << "\n";
    std::cout << "Active loans for " << professor->GetName() << ": "
         << loanService.CountActiveLoans(professor) << "/" << professor->GetMaxLoans() << "\n";

    return 0;
}