#pragma once

#include "State.hpp"

class IDynamic
{
public:
    virtual void setTarget(const State& target) = 0;
    virtual State next() = 0;
    virtual bool done() const = 0;
};