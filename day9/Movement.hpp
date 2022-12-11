#pragma once

#include <Eigen/Dense>
#include <string>

class Movement : public Eigen::Vector2i
{
public:
    using Eigen::Vector2i::Vector2i;
    Movement(const std::string& movement) {
        std::stringstream ss{movement};
        char dir;
        int dist;
        ss >> dir >> dist;
        switch (dir) {
        case 'U':
            *this << 0, dist;
            break;
        case 'D':
            *this << 0, -dist;
            break;
        case 'L':
            *this << -dist, 0;
            break;
        case 'R':
            *this << dist, 0;
            break;
        }
    }
};


template <typename T>
int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}
