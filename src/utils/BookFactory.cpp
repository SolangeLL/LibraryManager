#include "utils/BookFactory.hpp"
#include <stdexcept>

std::shared_ptr<IBook> BookFactory::Create(const std::string &type, const std::vector<std::string> &arguments)
{
    if (m_factory.count(type) == 0)
        throw std::invalid_argument("BookFactory can't create type '" + type + "'");

    return m_factory[type](arguments);
}
