#pragma once

#include "models/users/AUser.hpp"

class Professor : public AUser
{
public:
    using AUser::AUser;

    int GetMaxLoans() const override { return 10; }
    double GetPenaltyRate() const override { return 0.0; }
};