#pragma once

#include <string>

class AUser
{
public:
    AUser(const std::string &id, const std::string &name, const std::string &email)
        : m_id(id), m_name(name), m_email(email) {}

    virtual ~AUser() = default;

    std::string GetId() const { return m_id; }
    std::string GetName() const { return m_name; }
    std::string GetEmail() const { return m_email; }

    virtual int GetMaxLoans() const = 0;
    virtual double GetPenaltyRate() const = 0;

protected:
    std::string m_id;
    std::string m_name;
    std::string m_email;
};