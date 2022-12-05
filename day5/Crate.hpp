#pragma once
#include <regex>

class Crate {
public:
    Crate(char mark) : mark(mark) {}
    Crate(const std::string& box) {
        std::regex re{"\\[(?:\\w)\\]"};
        std::smatch match;
        if (std::regex_search(box, match, re)) {
            mark = match.str()[1];
        }
    }
    char getMark() const { return mark; }
private:
    char mark;
};
