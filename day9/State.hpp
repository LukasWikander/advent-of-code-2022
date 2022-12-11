#pragma once
#include <Eigen/Dense>
#include <utility>
class State : public Eigen::Vector2i
{
public:
    using Eigen::Vector2i::Vector2i;
    std::pair<int,int> asPair() const {
        return std::make_pair(x(),y());
    }
};
