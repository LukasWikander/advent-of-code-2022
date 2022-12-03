#pragma once

#include <set>
#include <string>
#include <algorithm>
#include "Rucksack.hpp"

class RucksackGroup
{
public:
    RucksackGroup(
        const std::string& input1,
        const std::string& input2,
        const std::string& input3)
        : firstRucksack(input1),
        secondRucksack(input2),
        thirdRucksack(input3) {}

    Item getSharedItem() const {
        std::set<Item> commonItemsFirstAndSecond;
        auto r1 = firstRucksack.getAllItems();
        auto r2 = secondRucksack.getAllItems();
        auto r3 = thirdRucksack.getAllItems();
        std::set_intersection(r1.begin(), r1.end(),
            r2.begin(), r2.end(),
            std::inserter(commonItemsFirstAndSecond, commonItemsFirstAndSecond.begin()));
        std::set<Item> commonItems;
        std::set_intersection(commonItemsFirstAndSecond.begin(), commonItemsFirstAndSecond.end(),
            r3.begin(), r3.end(),
            std::inserter(commonItems, commonItems.begin()));
        if (commonItems.size() == 0) {
            throw std::runtime_error("No common items");
        }
        else if (commonItems.size() > 1) {
            throw std::runtime_error("Multiple common items");
        }
        return *commonItems.begin();
    }

private:
    Rucksack firstRucksack;
    Rucksack secondRucksack;
    Rucksack thirdRucksack;
};
