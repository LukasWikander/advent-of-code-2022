#pragma once

#include <iostream>

#include "State.hpp"
#include "Movement.hpp"
#include "Located.hpp"
#include "IDynamic.hpp"

class Head : public Located, public IDynamic
{
public:
    Head(const State& initial) : target{initial}, Located{initial} {}

    void setTarget(const State& t) override {
        target = t;
    }
    State next() override {
        auto distance = target - current;
        current += Movement{sgn(distance.x()), sgn(distance.y())};
        return current;
    }
    bool done() const override {
        return current == target;
    }
private:
    State target;
};
