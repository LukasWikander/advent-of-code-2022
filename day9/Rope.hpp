#pragma once

#include "Head.hpp"
#include "Tail.hpp"

class Rope
{
public:
    Rope(const State& initial) : head{initial}, tail{initial} {}

    void setTarget(const State& target) {
        head.setTarget(target);
    }
    std::pair<State,State> next() {
        tail.setTarget(head.next());
        tail.next();
        return {head.getState(), tail.getState()};
    }
    bool done() const {
        return head.done();
    }

    State headState() const {
        return head.getState();
    }
    State tailState() const {
        return tail.getState();
    }
private:
    Head head;
    Tail tail;
};
