#include "SectionedPuzzleInput.hpp"
#include "Stacks.hpp"
#include "MoveOrder.hpp"

int main(int argc, char** argv) 
{
    SectionedPuzzleInput input{argv[1]};
    Stacks stacks(input[0]);
    MoveOrder moves(input[1]);
    std::cout << "Before any moves:" << std::endl;
    stacks.print();
    for (const auto& move : moves) {
        stacks.moveSeveral(std::get<1>(move)-1, std::get<2>(move)-1, std::get<0>(move));
    }
    std::cout << "After all moves:" << std::endl;
    stacks.print();
    return 0;
}
