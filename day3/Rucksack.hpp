#pragma once

#include <string>
#include <algorithm>
#include <set>

#include "Compartment.hpp"
#include "Item.hpp"

class Rucksack
{
public:
    Rucksack(const std::string& input)
        : firstCompartment(input.substr(0, input.length()/2)),
        secondCompartment(input.substr(input.length()/2)) {}
    
    Item getSharedItem() const {
        std::set<Item> sharedItems;
        std::set_intersection(firstCompartment.begin(), firstCompartment.end(),
            secondCompartment.begin(), secondCompartment.end(),
            std::inserter(sharedItems, sharedItems.begin()));
        if (sharedItems.size() == 0) {
            throw std::runtime_error("No shared items");
        }
        else if (sharedItems.size() > 1) {
            throw std::runtime_error("Multiple shared items");
        }
        return *sharedItems.begin();
    }

    std::set<Item> getAllItems() const {
        std::set<Item> allItems;
        std::set_union(firstCompartment.begin(), firstCompartment.end(),
            secondCompartment.begin(), secondCompartment.end(),
            std::inserter(allItems, allItems.begin()));
        return allItems;
    }
private:
    Compartment firstCompartment;
    Compartment secondCompartment;
};
