#pragma once

#include "interfaces/INotificationService.hpp"
#include <iostream>

class EmailNotificationService : public INotificationService
{
public:
    void Notify(const std::string &recipient, const std::string &message) override
    {
        std::cout << "[EMAIL] To: " << recipient << " | " << message << std::endl;
    }
};
