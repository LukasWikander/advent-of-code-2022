#pragma once

#include <utility>
#include <vector>

#include "AssignmentListing.hpp"
#include "Assignment.hpp"

class AssignmentPairCollection : public std::vector<std::pair<Assignment, Assignment>>
{
public:
    AssignmentPairCollection(const AssignmentListing& input) {
        for (auto& range : input) {
            emplace_back(range.substr(0,range.find_first_of(',')),
                range.substr(range.find_first_of(',')+1));
        }
    }
};
