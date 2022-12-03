#pragma once

#include <vector>

#include "ContentList.hpp"
#include "RucksackGroup.hpp"

class RucksackGroupCollection : public std::vector<RucksackGroup>
{
public:
    RucksackGroupCollection(ContentList input) {
        auto it = input.begin();
        while (it + 2 < input.end()) {
            emplace_back(*it, *(it + 1), *(it + 2));
            it += 3;
        }
    }
};