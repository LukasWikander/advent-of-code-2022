#pragma once

#include <vector>

#include "Elf.hpp"
#include "FoodList.hpp"
#include "Food.hpp"

class ElfCollection : public std::vector<Elf> {
public:
    ElfCollection(const FoodList& list) {
        if (list.size() == 0) { return; }
        emplace_back();
        for (const auto& line : list) {
            if (line.empty()) {
                emplace_back();
            } else {
                back().addFood(Food(std::stoi(line)));
            }
        }
    }
};
