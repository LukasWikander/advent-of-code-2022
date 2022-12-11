#pragma once

class LeafNode;
class TreeNode;
class InternalNode;

class IVisitor
{
public:
    virtual void visit(const LeafNode& node) = 0;
    virtual void visit(const TreeNode& node) = 0;
    virtual void visit(const InternalNode& node) = 0;
};
