#pragma once
#include <string>
#include "Card.hpp"

enum class SpellType
{
    Normal, Equip, Continuous, QuickPlay, Field
};
std::string to_string(const SpellType spelltype)
{
    switch (spelltype)
    {
    case SpellType::Normal:
        return "Normal";
    case SpellType::Equip:
        return "Equip";
    case SpellType::Continuous:
        return "Continuous";
    case SpellType::QuickPlay:
        return "Quick-Play";
    case SpellType::Field:
        return "Field";
    }
}

class Spell : public Card
{
private:
    std::string _id;
    std::string _name;
    SpellType _type;
public:
    Spell(const std::string& id, const std::string name, const SpellType& type)
    : Card{ id, CardType::Spell }
    , _type { type }
    {
        Card::set_name(name);
        _symbol = u8"魔";
    }
    const SpellType& get_spell_type() const
    {
        return _type;
    }
};