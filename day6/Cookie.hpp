#pragma once
#include <string>
#include <algorithm>
#include <iostream>

class Cookie
{
public:
    Cookie(std::string::const_iterator begin, int length)
        : begin{begin}, length{length} {}
    bool isValid() const
    {
        return length == 1 || (std::none_of(begin+1, begin+length, [&](char c){ return c == *begin; })
            && Cookie{begin+1, length-1}.isValid());
    }
private:
    std::string::const_iterator begin;
    int length;
};
