#include "InstructionList.hpp"
#include "Register.hpp"
#include "Instruction.hpp"
#include "CRT.hpp"

#include <iostream>
#include <sstream>
#include <vector>
#include <numeric>

int calcSignalStrengthSum(const RegisterLog& log)
{
    std::vector<int> idx = {19, 59, 99, 139, 179, 219};
    return std::accumulate(idx.begin(), idx.end(), 0, [&](int sum, int i) {
        std::cout << "log[" << i << "] = " << log[i] << std::endl;
        return sum + (i+1)*log[i];
    });
}

int main(int argc, char** argv)
{
    InstructionList instructions{argv[1]};
    Register reg{1};
    RegisterLog regLog;
    std::string instr, num;
    for (auto instruction : instructions) {
        std::stringstream ss{instruction};
        ss >> instr >> num;
        if (instr == "addx") {
            Addx addx{std::stoi(num)};
            addx.execute(reg, regLog);
        } else if (instr == "noop") {
            Noop noop;
            noop.execute(reg, regLog);
        }
    }
    std::cout << "The sum of the signal strengths is " << calcSignalStrengthSum(regLog) << std::endl;

    CRT crt{regLog, 40, 6};
    crt.printScreen();

    return 0;
}
