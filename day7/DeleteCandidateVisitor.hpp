#pragma once
#include <limits>
#include "IVisitor.hpp"

class DeleteCandidateVisitor : public IVisitor
{
public:
    DeleteCandidateVisitor(int limit) : limit(limit) {}

    virtual void visit(const LeafNode& node) override;
    virtual void visit(const TreeNode& node) override;
    virtual void visit(const InternalNode& node) override;

    int getSize() const { return size; }
private:
    int limit = 0;
    int size = std::numeric_limits<int>::max();
};
