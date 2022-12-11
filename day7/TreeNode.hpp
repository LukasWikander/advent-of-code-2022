#pragma once

#include "ISized.hpp"
#include "IPrintable.hpp"
#include "IVisitor.hpp"
#include <memory>

class TreeNode : public ISized, IPrintable
{
public:
    virtual void print(int nSpaces) const override {}
    virtual void accept(IVisitor& visitor) = 0;
};
