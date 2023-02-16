#pragma once
#include <string>
#include "Card.hpp"

enum class TrapType
{
    Normal, Continuous, Counter
};
std::string to_string(const TrapType traptype)
{
    switch (traptype)
    {
    case TrapType::Normal:
        return "Normal";
    case TrapType::Continuous:
        return "Continuous";
    case TrapType::Counter:
        return "Counter";
    }
}
class Trap : public Card
{
private:
    std::string _id;
    std::string _name;
    TrapType _type;
public:
    Trap(const std::string id, const std::string name, const TrapType& type)
    : Card{ id, CardType::Trap }
    , _type { type }
    {
        Card::set_name(name);
        _symbol = u8"罠";
    };
    
    const TrapType& get_trap_type() const
    {
        return _type;
    }
};
