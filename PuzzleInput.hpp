#pragma once

#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>

class PuzzleInput : public std::vector<std::string> {
public:
    PuzzleInput(const std::string& input) {
        if (std::filesystem::is_regular_file(input)) {
            std::ifstream is{input};
            std::string line;
            while (std::getline(is, line)) {
                push_back(line);
            }
        }
        else {
            std::istringstream is{input};
            std::string line;
            while (std::getline(is, line)) {
                push_back(line);
            }
        }
    }
    
    PuzzleInput() = default;
};
