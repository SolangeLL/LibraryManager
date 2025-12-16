#pragma once

#include "interfaces/IRepository.hpp"
#include <iostream>

class FileRepository : public IRepository
{
public:
    void Save(const std::string &data) override
    {
        std::cout << "[FILE] Save: " << data << std::endl;
    }

    std::string Load(const std::string &id) override
    {
        std::cout << "[FILE] Loading: " << id << std::endl;
        return "data";
    }
};
