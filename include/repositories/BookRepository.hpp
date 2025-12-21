#pragma once

#include <memory>
#include <iostream>
#include <unordered_map>
#include "interfaces/IRepository.hpp"
#include "models/books/ABook.hpp"

class BookRepository : public IRepository<ABook>
{
public:
    void Save(const ABook&& data) override
    {
        std::cout << "[FILE] Save: " << data.GetTitle() << std::endl;
    }

    std::shared_ptr<ABook> Get(const std::string &id) override
    {
        if (m_data.count(id) == 0)
            throw std::runtime_error("BookRepository does not have book id '" + id + "'");
        return m_data.at(id);
    }
private:
    std::unordered_map<std::string, std::shared_ptr<ABook>> m_data;
};
