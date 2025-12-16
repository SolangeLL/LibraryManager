#pragma once

#include "domain/entities/Loan.hpp"
#include "interfaces/INotificationService.hpp"

class LoanService
{
public:
    LoanService(std::shared_ptr<INotificationService> notificationService);

    bool CreateLoan(std::shared_ptr<AUser> user, std::shared_ptr<ABook> book);
    bool ReturnBook(const std::string &loadId);
    int CountActiveLoans(std::shared_ptr<AUser> user) const;
    std::vector<std::shared_ptr<Loan>> GetOverdueLoans() const;

private:
    std::vector<std::shared_ptr<Loan>> m_loans;
    std::shared_ptr<INotificationService> m_notificationService;
};