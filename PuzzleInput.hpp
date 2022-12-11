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
            std::cout << "Using input file " << input << std::endl;
            std::ifstream is{input};
            std::string line;
            while (std::getline(is, line)) {
                push_back(line);
            }
        }
        else {
            std::cout << "Using data string " << input << std::endl;
            std::istringstream is{input};
            std::string line;
            while (std::getline(is, line)) {
                push_back(line);
            }
        }
    }
    
    PuzzleInput() = default;
};
