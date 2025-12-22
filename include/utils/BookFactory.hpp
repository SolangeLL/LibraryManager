#pragma once

#include <unordered_map>
#include <string>
#include <functional>
#include <memory>
#include "types/ParsedInput.hpp"
// #include "models/books/ABook.hpp"
#include "interfaces/IBook.hpp"

class BookFactory
{
public:
    template <typename T>
    void RegisterType(const std::string &type)
    {
        m_factory[type] = [](const std::vector<std::string> &arguments)
        { return std::make_shared<T>(arguments); };
    }

    std::shared_ptr<IBook> Create(const std::string &type, const std::vector<std::string> &arguments);

private:
    std::unordered_map<std::string, std::function<std::shared_ptr<IBook>(const std::vector<std::string> &)>> m_factory;
};
