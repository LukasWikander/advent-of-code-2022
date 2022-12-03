#pragma once

enum class ShapeType
{
    Rock,
    Paper,
    Scissors
};

int getValue(ShapeType shape)
{
    switch (shape)
    {
    case ShapeType::Rock:
        return 1;
    case ShapeType::Paper:
        return 2;
    case ShapeType::Scissors:
        return 3;
    }
    throw std::runtime_error("Invalid shape");
}

ShapeType getWinningShape(ShapeType vsShape)
{
    switch (vsShape)
    {
    case ShapeType::Rock:
        return ShapeType::Paper;
    case ShapeType::Paper:
        return ShapeType::Scissors;
    case ShapeType::Scissors:
        return ShapeType::Rock;
    }
    throw std::runtime_error("Invalid shape");
}

ShapeType getLosingShape(ShapeType vsShape)
{
    switch (vsShape)
    {
    case ShapeType::Rock:
        return ShapeType::Scissors;
    case ShapeType::Paper:
        return ShapeType::Rock;
    case ShapeType::Scissors:
        return ShapeType::Paper;
    }
    throw std::runtime_error("Invalid shape");
}

ShapeType getTiedShape(ShapeType vsShape)
{
    switch (vsShape)
    {
    case ShapeType::Rock:
        return ShapeType::Rock;
    case ShapeType::Paper:
        return ShapeType::Paper;
    case ShapeType::Scissors:
        return ShapeType::Scissors;
    }
    throw std::runtime_error("Invalid shape");
}

int getScore(ShapeType a, ShapeType b)
{
    if (a == getWinningShape(b)) {
        return 6;
    }
    else if (a == getTiedShape(b)) {
        return 3;
    }
    else if (a == getLosingShape(b)) {
        return 0;
    }
    throw std::runtime_error("Invalid shapes");
}

