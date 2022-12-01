#pragma once

#include <vector>
#include <string>
#include <filesystem>
#include <fstream>

class FoodList : public std::vector<std::string> {
public:
    FoodList(std::filesystem::path input) {
        std::ifstream ifs(input);
        std::string line;
        while (std::getline(ifs, line)) {
            push_back(line);
        }
    }
};
