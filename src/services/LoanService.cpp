#include "services/LoanService.hpp"
#include <iostream>

LoanService::LoanService(std::shared_ptr<INotificationService> notificationService)
    : m_notificationService(notificationService) {}

bool LoanService::CreateLoan(std::shared_ptr<AUser> user, std::shared_ptr<ABook> book)
{
    if (!book->IsAvailable())
    {
        std::cout << "The book is not available.\n";
        return false;
    }

    int activeLoans = CountActiveLoans(user);
    if (activeLoans >= user->GetMaxLoans())
    {
        std::cout << "Loan limit reached for this user.\n";
        return false;
    }

    auto now = std::chrono::system_clock::now();
    auto due = now + std::chrono::hours(24 * book->GetMaxLoanDays());

    std::string loanId = "LOAN_" + std::to_string(m_loans.size() + 1);
    auto loan = std::make_shared<Loan>(loanId, user, book, now, due);

    m_loans.push_back(loan);
    book->SetAvailable(false);

    m_notificationService->Notify(
        user->GetEmail(),
        "Loan confirmed: " + book->GetTitle());

    std::cout << "Loan created successfully! ID: " << loanId << "\n";
    return true;
}

bool LoanService::ReturnBook(const std::string &loanId)
{
    for (auto &loan : m_loans)
    {
        if (loan->GetId() == loanId && !loan->IsReturned())
        {
            loan->MarkAsReturned();
            loan->GetBook()->SetAvailable(true);

            double latePenalty = loan->CalculateLatePenalty();
            if (latePenalty > 0)
            {
                std::cout << "Late penalty: " << latePenalty << "€\n";
            }

            m_notificationService->Notify(
                loan->GetUser()->GetEmail(),
                "Book returned: " + loan->GetBook()->GetTitle());

            return true;
        }
    }
    return false;
}

int LoanService::CountActiveLoans(std::shared_ptr<AUser> user) const
{
    int count = 0;
    for (const auto &loan : m_loans)
    {
        if (loan->GetUser()->GetId() == user->GetId() && !loan->IsReturned())
        {
            count++;
        }
    }
    return count;
}

std::vector<std::shared_ptr<Loan>> LoanService::GetOverdueLoans() const
{
    std::vector<std::shared_ptr<Loan>> overdue;
    for (const auto &loan : m_loans)
    {
        if (!loan->IsReturned() && loan->GetDaysOverdue() > 0)
        {
            overdue.push_back(loan);
        }
    }
    return overdue;
}