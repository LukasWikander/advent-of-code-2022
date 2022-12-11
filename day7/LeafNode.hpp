#pragma once
#include <string>
#include <iostream>

#include "TreeNode.hpp"

class LeafNode : public TreeNode
{
public:
    LeafNode(int size) : size(size) {}

    virtual int getSize() const override { return size; }
    virtual void print(int nSpaces) const override
    {}
    virtual void accept(IVisitor& visitor) override
    {
        visitor.visit(*this);
    }

private:
    int size;
};