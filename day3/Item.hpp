#pragma once
#include <stdexcept>

class Item
{
public:
    Item(char identifier) : identifier(identifier) {}

    int getPriority() const
    { 
        if (identifier >= 'A' && identifier <= 'Z') {
            return 27 + identifier - 'A';
        } else if (identifier >= 'a' && identifier <= 'z') {
            return 1 + identifier - 'a';
        }
        throw std::runtime_error("Invalid identifier");
    }

    bool operator==(const Item& other) const
    {
        return identifier == other.identifier;
    }

    bool operator<(const Item& other) const
    {
        return identifier < other.identifier;
    }

private:
    char identifier;
};
