#pragma once

#include <memory>
#include <iostream>
#include <unordered_map>
#include "interfaces/IBookRepository.hpp"
#include "models/books/ABook.hpp"

class InMemoryBookRepository : public IBookRepository
{
public:
    void Save(std::shared_ptr<IBook> data) override;

    std::shared_ptr<IBook> GetById(const std::string &id) override;
    std::vector<std::shared_ptr<IBook>> GetAll() override;
    void DeleteById(const std::string &id) override;
    std::string GetNextId() override;

private:
    std::unordered_map<std::string, std::shared_ptr<IBook>> m_books;
};
