#include "UpdatedStrategyGuide.hpp"
#include <numeric>
#include <iostream>

int main(int argc, char** argv)
{
    auto guide = UpdatedStrategyGuide{argv[1]};
    auto score = std::accumulate(guide.cbegin(), guide.cend(), 0, [](int sum, std::pair<ShapeType,ShapeType> pair) {
        return sum + getScore(pair.second, pair.first);
    });
    auto value = std::accumulate(guide.cbegin(), guide.cend(), 0, [](int sum, std::pair<ShapeType,ShapeType> pair) {
        return sum + getValue(pair.second);
    });
    std::cout << "The sum of score and value is " << score + value << std::endl;
}
