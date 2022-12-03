#pragma once

#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include <utility>

#include "Shape.hpp"

class StrategyGuide : public std::vector<std::pair<ShapeType,ShapeType>>
{
public:
    StrategyGuide(std::filesystem::path input) {
        std::ifstream ifs(input);
        std::string line;
        while (std::getline(ifs, line)) {
            push_back(parseLine(line));
        }
    }
private:
    std::pair<ShapeType,ShapeType> parseLine(std::string line)
    {
        auto space = line.find(' ');
        auto a = line.substr(0, space);
        auto b = line.substr(space + 1);
        return std::make_pair(parseShape(a), parseShape(b));
    }
    
    ShapeType parseShape(std::string shape)
    {
        if (shape == "A" || shape == "X") {
            return ShapeType::Rock;
        } else if (shape == "B" || shape == "Y") {
            return ShapeType::Paper;
        } else if (shape == "C" || shape == "Z") {
            return ShapeType::Scissors;
        }
        throw std::runtime_error("Invalid shape: " + shape);
    }
};
