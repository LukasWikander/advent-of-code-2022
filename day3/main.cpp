#include <iostream>
#include <numeric>
#include "ContentList.hpp"
#include "RucksackCollection.hpp"
#include "RucksackGroupCollection.hpp"

int main(int argc, char** argv)
{
    auto list = ContentList{argv[1]};
    auto rucksacks = RucksackCollection(list);
    auto rucksackGroups = RucksackGroupCollection(list);
    auto prioritySum = std::accumulate(rucksacks.cbegin(), rucksacks.cend(), 0, [](int sum, Rucksack rucksack) {
        return sum + rucksack.getSharedItem().getPriority();
    });
    std::cout << "The sum of priorities is " << prioritySum << std::endl;
    auto badgePrioritySum = std::accumulate(rucksackGroups.cbegin(), rucksackGroups.cend(), 0, [](int sum, RucksackGroup group) {
        return sum + group.getSharedItem().getPriority();
    });
    std::cout << "The sum of badge priorities is " << badgePrioritySum << std::endl;
}
