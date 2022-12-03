#pragma once

#include "Rucksack.hpp"

#include <vector>
#include <string>
#include <filesystem>
#include <fstream>

#include "Rucksack.hpp"
#include "ContentList.hpp"

class RucksackCollection : public std::vector<Rucksack> {
public:
    RucksackCollection(ContentList input) {
        for (auto content : input) {
            emplace_back(content);
        }
    }
};
