#pragma once

#include <memory>
#include <iostream>
#include <unordered_map>
#include "interfaces/IRepository.hpp"
#include "models/users/AUser.hpp"

class UserRepository : public IRepository<AUser>
{
public:
    void Save(std::shared_ptr<AUser> data) override
    {
        std::cout << "[FILE] Save: " << data->GetName() << std::endl;
    }

    std::shared_ptr<AUser> Get(const std::string &id) override
    {
        if (m_users.count(id) == 0)
            throw std::runtime_error("UserRepository does not have user id '" + id + "'");
        return m_users.at(id);
    }
private:
    std::unordered_map<std::string, std::shared_ptr<AUser>> m_users;
};
