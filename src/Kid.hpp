#pragma once
#include <string>
#include <ostream>

class Kid
{
    public:
    Kid(const std::string& name, int money)
    : _name {name}
    , _money {money}
    {}

    const std::string& get_name() const
    {
        return _name;
    }

    int get_money() const
    {
        return _money;
    }

    private:
    std::string _name;
    int _money;
};

std::ostream& operator<<(std::ostream& stream, const Kid& person)
{
    return stream << person.get_name() << " has " << person.get_money() << " euros.";
}