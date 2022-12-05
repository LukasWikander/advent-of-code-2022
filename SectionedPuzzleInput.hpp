#pragma once
#include <algorithm>
#include "PuzzleInput.hpp"

#include <iostream>

class SectionedPuzzleInput : public std::vector<PuzzleInput>
{
public:
    SectionedPuzzleInput(std::filesystem::path input)
    {
        PuzzleInput in(input);
        auto sectionStart = in.begin();
        auto sectionStop = in.begin();
        while (sectionStop != in.end()) {
            sectionStop = std::find_if(sectionStart, in.end(), [](const auto& line) {
                return line.empty();
            });
            PuzzleInput section;
            std::copy(sectionStart, sectionStop, std::back_inserter(section));
            push_back(section);
            sectionStart = sectionStop+1;
        }
    }
};
