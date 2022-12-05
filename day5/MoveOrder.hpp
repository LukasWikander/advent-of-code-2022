#pragma once
#include <vector>
#include <tuple>
#include <sstream>
#include <iterator>

#include "PuzzleInput.hpp"

class MoveOrder : public std::vector<std::tuple<int, int, int>>
{
public:
    MoveOrder(const PuzzleInput& input) {
        for (const auto& line : input) {
            int num, from, to;
            std::string trash;
            std::istringstream ss(line);
            if (ss >> trash >> num >> trash >> from >> trash >> to) {
                push_back(std::make_tuple(num, from, to));
            }
        }
    }
};
