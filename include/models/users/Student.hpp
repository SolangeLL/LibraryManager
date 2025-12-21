#pragma once

#include "models/users/AUser.hpp"

class Student : public AUser
{
public:
    using AUser::AUser;

    int GetMaxLoans() const override { return 3; }
    double GetPenaltyRate() const override { return 0.50; }
};