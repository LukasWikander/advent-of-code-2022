#pragma once

#include <vector>

class Register
{
public:
    Register(int initial) : value(initial) {}
    Register& operator+=(int rhs) {
        value += rhs;
        return *this;
    }
    operator int() const {
        return value;
    }
private:
    int value;
};

class RegisterLog : public std::vector<int>
{
public:
    RegisterLog() : std::vector<int>() {}
    void log(int value) {
        push_back(value);
    }
};
