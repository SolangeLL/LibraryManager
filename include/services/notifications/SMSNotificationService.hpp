#pragma once

#include "interfaces/INotificationService.hpp"
#include <iostream>

class SMSNotificationService : public INotificationService
{
public:
    void Notify(const std::string &recipient, const std::string &message) override
    {
        std::cout << "[SMS] To: " << recipient << " | " << message << std::endl;
    }
};
