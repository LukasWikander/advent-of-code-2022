#pragma once
#include <vector>
#include <numeric>
#include "Food.hpp"

class Elf {
public:
    void addFood(Food food) {
        meals.push_back(food);
    }
    int getTotalCarriedCalories() const {
        return std::accumulate(meals.begin(), meals.end(), 0, [](int sum, Food food) {
            return sum + food.getCalories();
        });
    }
private:
    std::vector<Food> meals;
};
