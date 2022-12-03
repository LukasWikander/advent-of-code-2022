#pragma once

#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include <utility>

#include "Shape.hpp"

class UpdatedStrategyGuide : public std::vector<std::pair<ShapeType,ShapeType>>
{
public:
    UpdatedStrategyGuide(std::filesystem::path input) {
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
        return std::make_pair(parseShape(a), parseRequiredOutcome(b, parseShape(a)));
    }
    
    ShapeType parseShape(std::string shape)
    {
        if (shape == "A") {
            return ShapeType::Rock;
        } else if (shape == "B") {
            return ShapeType::Paper;
        } else if (shape == "C") {
            return ShapeType::Scissors;
        }
        throw std::runtime_error("Invalid shape: " + shape);
    }

    ShapeType parseRequiredOutcome(std::string outcome, ShapeType vsShape)
    {
        if (outcome == "X") {
            return getLosingShape(vsShape);
        } else if (outcome == "Y") {
            return getTiedShape(vsShape);
        } else if (outcome == "Z") {
            return getWinningShape(vsShape);
        }
        throw std::runtime_error("Invalid outcome: " + outcome);
    }
};
