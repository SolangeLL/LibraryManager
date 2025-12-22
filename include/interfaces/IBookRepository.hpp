#pragma once

#include <string>
#include <memory>
#include <vector>
#include "interfaces/IBook.hpp"

class IBookRepository {
public:
    virtual ~IBookRepository() = default;
    virtual void Save(std::shared_ptr<IBook> data) = 0;
    virtual std::shared_ptr<IBook> GetById(const std::string& id) = 0;
    virtual std::vector<std::shared_ptr<IBook>> GetAll() = 0;
    virtual void DeleteById(const std::string& id) = 0;
    virtual std::string GetNextId() = 0;
};
