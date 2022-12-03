#pragma once

#include <vector>
#include <string>
#include <filesystem>
#include <fstream>

class ContentList : public std::vector<std::string> {
public:
    ContentList(std::filesystem::path input) {
        std::ifstream ifs(input);
        std::string line;
        while (std::getline(ifs, line)) {
            push_back(line);
        }
    }
};
