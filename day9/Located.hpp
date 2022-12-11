#pragma once

#include "State.hpp"
#include <utility>

class Located
{
public:
    Located(const State& initial) : current{initial} {}
    State getState() const {
        return current;
    }

protected:
    State current;
};
