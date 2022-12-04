#include "AssignmentListing.hpp"
#include "AssignmentPairCollection.hpp"

#include <iostream>
#include <algorithm>

int main(int argc, char** argv) 
{
    AssignmentListing input{argv[1]};
    AssignmentPairCollection assignments(input);

    auto numIncludes = std::count_if(assignments.begin(), assignments.end(), [](const auto& pair) {
        return std::includes(
                pair.first.begin(), pair.first.end(),
                pair.second.begin(), pair.second.end())
            || std::includes(
                pair.second.begin(), pair.second.end(),
                pair.first.begin(), pair.first.end());
    });

    auto numOverlaps = std::count_if(assignments.begin(), assignments.end(), [](const auto& pair) {
        auto intersection = std::set<int>{};
        std::set_intersection(
                pair.first.begin(), pair.first.end(),
                pair.second.begin(), pair.second.end(),
                std::inserter(intersection, intersection.begin()));
        return !intersection.empty();
    });

    std::cout << "The number of overlapping assignments is " << numIncludes << std::endl;
    std::cout << "The number of overlapping assignments is " << numOverlaps << std::endl;
    return 0;
}
