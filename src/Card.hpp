#pragma once
#pragma once
#include <iostream>
#include <string>

enum class CardType 
{ 
    Monster, Spell, Trap 
};

std::string to_string(CardType cardType)
{
    switch(cardType)
    {
    case CardType::Monster : return "Monster";
    case CardType::Spell : return "Spell";
    case CardType::Trap : return "Trap";
    }
}
class Card
{
private:
    const std::string _id;
    const CardType _type;
    std::string _name;
    std::string _description;
protected:
    std::string _symbol;

public:
    Card(const std::string& id, const CardType& cardtype)
    : _id { id }
    , _type { cardtype }
    {}

    const std::string& get_id() const
    {
        return _id;
    }
    const CardType& get_type() const
    {
        return _type;
    }
    void set_name(const std::string& name)
    {
        _name = name;
    }
    void set_description(const std::string& description)
    {
        _description = description;
    }
    
    const std::string& get_name() const
    {
        return _name;
    }
    const std::string& get_description() const
    {
        return _description;
    }
    const std::string& get_symbol() const
    {
        return _symbol;
    }
    
};

