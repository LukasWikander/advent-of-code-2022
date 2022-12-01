#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>

#include "Elf.hpp"
#include "Food.hpp"
#include "FoodList.hpp"

std::vector<Elf> parseInput(const FoodList& list)
{
    if (list.size() == 0) { return std::vector<Elf>(); }
    std::vector<Elf> elves(1);
    for (const auto& line : list) {
        if (line.empty()) {
            elves.emplace_back();
        } else {
            elves.back().addFood(Food(std::stoi(line)));
        }
    }
    return elves;
}

int main(int argc, char** argv) {
    FoodList list(argv[1]);
    std::vector<Elf> elves = parseInput(list);
    std::sort(elves.begin(), elves.end(), [](Elf a, Elf b) {
        return a.getTotalCarriedCalories() < b.getTotalCarriedCalories();
    });
    auto sumCarriedCalories = std::accumulate(elves.crbegin(), elves.crbegin() + 3, 0, [](int sum, Elf elf) {
        return sum + elf.getTotalCarriedCalories();
    });
    std::cout << "The three most loaded elves carry a total of " << sumCarriedCalories << " calories." << std::endl;
    return 0;
}

