#pragma once

#include <vector>

#include "Head.hpp"
#include "Tail.hpp"

class LongRope
{
public:
    LongRope(const State& initial) : head{initial}, knots(9, initial) {}

    void setTarget(const State& target) {
        head.setTarget(target);
    }
    std::pair<State,State> next() {
        knots.front().setTarget(head.next());
        for (auto it = knots.begin()+1; it != knots.end(); ++it) {
            it->setTarget((it-1)->next());
        }
        return {head.getState(), knots.back().next()};
    }
    bool done() const {
        return head.done();
    }

    State headState() const {
        return head.getState();
    }
    State tailState() const {
        return knots.back().getState();
    }

    void print() const {
        for (int i = -13; i < 13; ++i) {
            for (int j = -13; j < 13; ++j) {
                if (headState() == State{i,j}) {
                    std::cout << "H";
                    continue;
                }
                auto match = std::find_if(
                    knots.begin(), knots.end(),
                    [i,j](const Tail& t) { 
                        return t.getState() == State{i,j};
                    });
                if (match != knots.end()) {
                    std::cout << std::distance(knots.begin(), match) + 1;
                    continue;
                }
                std::cout << ".";
            }
            std::cout << std::endl;
        }
    }
private:
    Head head;
    std::vector<Tail> knots;
};
