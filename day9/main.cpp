
#include "State.hpp"
#include "Movement.hpp"
#include "MovementList.hpp"
#include "Rope.hpp"
#include "LongRope.hpp"
#include <set>
#include <iostream>
#include <utility>


int main(int argc, char** argv)
{
    MovementList movements{argv[1]};
    Rope rope{State{0,0}};
    LongRope longRope{State{0,0}};
    std::set<std::pair<int,int>> shortVisited;
    std::set<std::pair<int,int>> longVisited;

    shortVisited.insert(rope.tailState().asPair());
    for (auto movement : movements) {
        rope.setTarget(rope.headState() + Movement{movement});
        while (!rope.done()) {
            auto [headPos, tailPos] = rope.next();
            shortVisited.insert(tailPos.asPair());
        }
    }
    std::cout << "There are " << shortVisited.size() << " visited locations for the short rope tail" << std::endl;

    longVisited.insert(longRope.tailState().asPair());
    for (auto movement : movements) {
        longRope.setTarget(longRope.headState() + Movement{movement});
        while (!longRope.done()) {
            auto [headPos, tailPos] = longRope.next();
            longVisited.insert(tailPos.asPair());
        }
    }
    std::cout << "There are " << longVisited.size() << " visited locations for the long rope tail" << std::endl;
    return 0;
}