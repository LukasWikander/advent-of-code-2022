#pragma once

class Food {
public:
    Food(int calories) : calories(calories) {}
    int getCalories() { return calories; }
private:
    int calories;
};
