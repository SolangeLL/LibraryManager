#pragma once

#include "domain/entities/users/AUser.hpp"

class Professor : public AUser
{
public:
    Professor(const std::string &id, const std::string &name, const std::string &email)
        : AUser(id, name, email) {}

    int GetMaxLoans() const override { return 10; }
    double GetPenaltyRate() const override { return 0.0; }
};