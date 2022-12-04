#pragma once

#include <set>
#include <string>

class Assignment : public std::set<int>
{
public:
    Assignment(const std::string& input)
    {
        auto start = input.substr(0, input.find_first_of('-'));
        auto end = input.substr(input.find_first_of('-') + 1);
        for (auto i = std::stoi(start); i <= std::stoi(end); ++i) {
            insert(i);
        }
    }
};
