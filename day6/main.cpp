#include "ProtocolData.hpp"
#include "Cookie.hpp"
#include <algorithm>
#include <iostream>

int main(int argc, char** argv)
{
    ProtocolData input{argv[1]};
    constexpr int size = 14;
    int distance = 0;
    for (auto it = input[0].cbegin(); it + size < input[0].cend(); it += 1) {
        if (Cookie{it, size}.isValid()) {
            distance = std::distance(input[0].cbegin(), it)+size;
            break;
        }
    }
    std::cout << "Number of processed bytes is " << distance << std::endl;
}