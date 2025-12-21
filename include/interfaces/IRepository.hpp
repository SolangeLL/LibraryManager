#pragma once

#include <string>

template <typename T>
class IRepository {
public:
    virtual ~IRepository() = default;
    virtual void Save(const T&& data) = 0;
    virtual std::shared_ptr<T> Get(const std::string& id) = 0;
    virtual void Delete(const std::string& id) = 0;
};
