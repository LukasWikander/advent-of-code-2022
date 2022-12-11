#pragma once

#include <iostream>

#include "State.hpp"
#include "Movement.hpp"
#include "Located.hpp"
#include "IDynamic.hpp"

class Tail : public Located, public IDynamic
{
public:
    Tail(const State& initial) : target{initial}, Located{initial} {}

    void setTarget(const State& t) override {
        target = t;
    }
    State next() override {
        auto distance = target - current;
        int tailXMovement;
        int tailYMovement;
        if (distance.norm() < 2) {
            tailXMovement = distance.x() > 1 ? 1 : distance.x() < -1 ? -1 : 0;
            tailYMovement = distance.y() > 1 ? 1 : distance.y() < -1 ? -1 : 0;
        }
        else {
            tailXMovement = sgn(distance.x());
            tailYMovement = sgn(distance.y());
        }
        current += Movement{tailXMovement, tailYMovement};
        return current;
    }
    bool done() const override {
        return (current - target).norm() < 2;
    }
private:
    State target;
};
