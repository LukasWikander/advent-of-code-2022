#include <algorithm>
#include <iostream>

#include "Elf.hpp"
#include "Food.hpp"
#include "FoodList.hpp"
#include "ElfCollection.hpp"

int main(int argc, char** argv) {
    auto elves = ElfCollection(FoodList{argv[1]});
    std::sort(elves.begin(), elves.end(), [](Elf a, Elf b) {
        return a.getTotalCarriedCalories() < b.getTotalCarriedCalories();
    });
    auto sumCarriedCalories = std::accumulate(elves.crbegin(), elves.crbegin() + 3, 0, [](int sum, Elf elf) {
        return sum + elf.getTotalCarriedCalories();
    });
    std::cout << "The most loaded elf carries " << elves.back().getTotalCarriedCalories() << " calories." << std::endl;
    std::cout << "The three most loaded elves carry a total of " << sumCarriedCalories << " calories." << std::endl;
    return 0;
}
