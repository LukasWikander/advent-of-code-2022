#pragma once

#include "IVisitor.hpp"

class SizeAdderVisitor : public IVisitor
{
public:
    SizeAdderVisitor(int limit) : limit(limit) {}

    virtual void visit(const LeafNode& node) override;
    virtual void visit(const TreeNode& node) override;
    virtual void visit(const InternalNode& node) override;

    int getSum() const { return sum; }
private:
    int sum = 0;
    int limit = 0;
};
