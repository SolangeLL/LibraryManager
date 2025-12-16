#pragma once

#include "domain/entities/users/AUser.hpp"

class Student : public AUser
{
public:
    Student(const std::string &id, const std::string &name, const std::string &email)
        : AUser(id, name, email) {}

    int GetMaxLoans() const override { return 3; }
    double GetPenaltyRate() const override { return 0.50; }
};