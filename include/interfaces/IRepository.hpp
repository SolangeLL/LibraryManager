#pragma once

#include <string>

class IRepository {
public:
    virtual ~IRepository() = default;
    virtual void Save(const std::string& data) = 0;
    virtual std::string Load(const std::string& id) = 0;
};
