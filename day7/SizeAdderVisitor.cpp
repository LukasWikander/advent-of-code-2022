#include "SizeAdderVisitor.hpp"
#include "InternalNode.hpp"
#include "LeafNode.hpp"
#include "TreeNode.hpp"


void SizeAdderVisitor::visit(const LeafNode& node) {
}
void SizeAdderVisitor::visit(const TreeNode& node) {
}
void SizeAdderVisitor::visit(const InternalNode& node) {
    if (node.getSize() <= limit) {
        sum += node.getSize();
    }
}

