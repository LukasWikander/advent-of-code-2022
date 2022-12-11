#include "DeleteCandidateVisitor.hpp"
#include "InternalNode.hpp"
#include "LeafNode.hpp"
#include "TreeNode.hpp"


void DeleteCandidateVisitor::visit(const LeafNode& node) {
}
void DeleteCandidateVisitor::visit(const TreeNode& node) {
}
void DeleteCandidateVisitor::visit(const InternalNode& node) {
    if (node.getSize() >= limit) {
        size = std::min(size, node.getSize());
    }
}

