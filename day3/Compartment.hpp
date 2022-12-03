#pragma once

#include <set>
#include <string>

#include "Item.hpp"


class Compartment : public std::set<Item>
{
public:
    Compartment(const std::string& input) {
        for (auto c : input) {
            insert(Item(c));
        }
    }
};
