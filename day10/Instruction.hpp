#pragma once

#include "Register.hpp"

class Instruction
{
public:
    Instruction(int cycleCount) : cycleCount(cycleCount) {}
    void execute(Register& reg, RegisterLog& log) {}
protected:
    const int cycleCount;
};

class Addx : public Instruction
{
public:
    Addx(int value) : Instruction(2), value(value) {}

    void execute(Register& reg, RegisterLog& log) {
        for (int i = 0; i < cycleCount; ++i) {
            log.log(reg);
        }
        reg += value;
    }
private:
    const int value;
};

class Noop : public Instruction
{
public:
    Noop() : Instruction(1) {}

    void execute(Register& reg, RegisterLog& log) {
        for (int i = 0; i < cycleCount; ++i) {
            log.log(reg);
        }
    }
};
