#pragma once

#include <string>

class INotificationService {
public:
    virtual ~INotificationService() = default;
    virtual void Notify(const std::string& recipient, const std::string& message) = 0;
};
