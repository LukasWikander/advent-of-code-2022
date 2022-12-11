#pragma once

#include "CommandListing.hpp"
#include "InternalNode.hpp"
#include "LeafNode.hpp"
#include "SizeAdderVisitor.hpp"
#include "DeleteCandidateVisitor.hpp"


bool isCommand(const std::string& line)
{
    return line[0] == '$';
}

bool isUp(const std::string& line)
{
    return isCommand(line) && !line.compare(2, 5, "cd ..");
}

bool isDown(const std::string& line)
{
    return isCommand(line) && !line.compare(2, 2, "cd") && !isUp(line);
}

void fillContents(std::shared_ptr<InternalNode> node, const CommandListing& listing, CommandListing::const_iterator& it)
{
    std::string word1, word2, word3;
    while (it < listing.end() && !isUp(*it)) {
        if (isCommand(*it)) {
            if (isDown(*it)) {
                std::istringstream iss{*it};
                iss >> word1 >> word2 >> word3;
                auto child = std::make_shared<InternalNode>();
                fillContents(child, listing, ++it);
                node->add(word3, child);
            }
        } else {
            std::istringstream iss{*it};
            iss >> word1 >> word2;
            if (!word1.compare("dir")) {
                node->add(word2, std::make_shared<InternalNode>());
            }
            else if (isdigit(word1[0])) {
                node->add(word2, std::make_shared<LeafNode>(std::stoi(word1)));
            }
        }
        ++it;
    }
}

class FileSystemMap
{
public:
    FileSystemMap(const CommandListing& listing) {
        CommandListing::const_iterator it = listing.begin();
        root = std::make_shared<InternalNode>();
        fillContents(root, listing, it);
        root->print(0);

        SizeAdderVisitor sizeVisitor{100000};
        root->accept(sizeVisitor);
        std::cout << "Summed size larger than 100000: " << sizeVisitor.getSum() << std::endl;

        auto unusedSpace = 70000000 - root->getSize();
        auto requiredAdditionalSpace = 30000000 - unusedSpace;

        DeleteCandidateVisitor deleteVisitor{requiredAdditionalSpace};
        root->accept(deleteVisitor);
        std::cout << "Size of delete candidate: " << deleteVisitor.getSize() << std::endl;
    }

private:
    std::shared_ptr<InternalNode> root;
};
