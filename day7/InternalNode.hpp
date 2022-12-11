#pragma once
#include <numeric>
#include <map>
#include <iostream>
#include <string>
#include <memory>
#include "TreeNode.hpp"

class InternalNode : public TreeNode
{
public:
    InternalNode() {}
    virtual void add(const std::string& name, std::shared_ptr<TreeNode> node) {
        nodes[name] = node;
    }

    virtual int getSize() const override
    {
        return std::accumulate(nodes.begin(), nodes.end(), 0,
            [](int size, const std::pair<std::string,std::shared_ptr<TreeNode>>& node) { return size + node.second->getSize(); });
    }

    void print(int nSpaces) const override
    {
        for (const auto& node : nodes) {
            for (int i = 0; i < nSpaces; ++i) std::cout << " ";
            std::cout << node.first << " (" << node.second->getSize() << ")" << std::endl;
            node.second->print(nSpaces+2);
        }
    }

    void accept(IVisitor& visitor) override
    {
        visitor.visit(*this);
        for (const auto& node : nodes) {
            node.second->accept(visitor);
        }
    }

private:
    std::map<std::string,std::shared_ptr<TreeNode>> nodes;
};
