#pragma once

#include "../lib/Consumable.hpp"
#include "../lib/Cupboard.hpp"
#include "../lib/Ingredient.hpp"
#include "../lib/Recipe.hpp"
#include "../lib/Unit.hpp"

#include <optional>
#include <random>
#include <set>
#include <memory>
#include <string>
#include <utility>

class Kitchen
{
    private:
    
    struct Comparator
    {
        bool compare_insensitive(const std::string& s1, const std::string& s2) const
        {
            return std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(),
                                                [](char c1, char c2) { return tolower(c1) < tolower(c2); });
        }
        bool operator()(const Unit& u1, const Unit& u2) const { return u1.name < u2.name; }
        bool operator()(const Ingredient& i1, const Ingredient& i2) const
        {
            return compare_insensitive(i1.name, i2.name);
        }

    };
    
    std::set<Unit, Comparator> _units;
    std::set<Ingredient, Comparator> _ingredients;

    public:
    const Unit& register_unit(Unit unit) 
    {
        auto pair = _units.emplace(std::move(unit));
        return *pair.first;
    }
    
    const Unit* find_unit(const std::string& name) const
    {
        auto newUnit = Unit{name};
        const auto it = _units.find(newUnit);
        return it != _units.end() ? &(*it) : nullptr;
    }

    const Ingredient& register_ingredient(Ingredient ingredient)
    {
        const auto pair = _ingredients.emplace(std::move(ingredient));
        return *pair.first;
    }

    const Ingredient* find_ingredient(const std::string& name) const
    {
        auto u = new Unit{ " "};
        const auto newIngredient = Ingredient{name, *u};
        const auto it = _ingredients.find(newIngredient);
        return it != _ingredients.end() ? &(*it) : nullptr;
    }
};
