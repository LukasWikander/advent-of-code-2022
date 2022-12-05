#pragma once

#include <vector>
#include <regex>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <sstream>

#include "Stack.hpp"
#include "PuzzleInput.hpp"

class Stacks : public std::vector<Stack>
{
public:
    Stacks(const PuzzleInput& input) {
        std::istringstream ss(input.back());
        resize(std::distance(std::istream_iterator<int>(ss), std::istream_iterator<int>()));
        std::regex re{"\\s?(?:\\[\\w\\]|   )"};
        for (auto row = input.crbegin()+1; row != input.crend(); ++row) {
            int i = 0;
            for (auto crate = std::sregex_iterator(row->begin(), row->end(), re);
                    crate != std::sregex_iterator(); ++crate, ++i) {
                if (crate->str().find_first_of("[]") != std::string::npos) {
                    auto& stack = at(i);
                    stack.push_back(Crate{crate->str()});
                }
            }
        }
    }

    void moveIndividually(int from, int to, int num)
    {
        auto& fromStack = at(from);
        auto& toStack = at(to);
        std::reverse_copy(fromStack.end()-num, fromStack.end(), std::back_inserter(toStack));
        fromStack.erase(fromStack.end()-num, fromStack.end());
    }

    void moveSeveral(int from, int to, int num)
    {
        auto& fromStack = at(from);
        auto& toStack = at(to);
        std::copy(fromStack.end()-num, fromStack.end(), std::back_inserter(toStack));
        fromStack.erase(fromStack.end()-num, fromStack.end());
    }

    void print() const
    {
        for (const auto& stack : *this) {
            for (const auto& crate : stack) {
                std::cout << "[" << crate.getMark() << "]";
            }
            std::cout << std::endl;
        }
    }
};
