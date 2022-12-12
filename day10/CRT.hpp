#pragma once

#include <eigen3/Eigen/Dense>
#include "Register.hpp"

#include <iostream>

class CRT
{
public:
    CRT(
        const RegisterLog& log,
        int numScreenColumns,
        int numScreenRows)
        : numScreenColumns{numScreenColumns},
        numScreenRows{numScreenRows}
    {
        spriteLocations.resize(numScreenColumns*numScreenRows, log.size());
        spriteLocations.setZero();
        for (int i = 0; i < log.size(); ++i) {
            int centerPixel = log[i] + i/numScreenColumns*numScreenColumns;
            int startPixel = std::max(centerPixel-1, 0);
            int endPixel = std::min(centerPixel+1, numScreenColumns*numScreenRows-1);
            int numDrawnPixels = std::min(endPixel - startPixel + 1, 3);
            spriteLocations.block(startPixel, i, numDrawnPixels, 1).setOnes();
        }
    }
    void printScreen() const {
        auto screen = spriteLocations.diagonal();
        for (int i = 0; i < numScreenRows; ++i) {
            for (int j = 0; j < numScreenColumns; ++j) {
                std::cout << (screen[i*numScreenColumns+j] > 0 ? "#" : ".");
            }
            std::cout << std::endl;
        }
    }
private:
    Eigen::MatrixXi spriteLocations; // pixel index x time
    int numScreenColumns;
    int numScreenRows;
};
