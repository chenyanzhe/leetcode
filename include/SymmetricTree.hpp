#ifndef SYMMETRIC_TREE_HPP_
#define SYMMETRIC_TREE_HPP_

#include "TreeNode.hpp"

class SymmetricTree {
public:
    bool isSymmetric(TreeNode *root);

private:
    bool isSymmetricHelper(TreeNode *l, TreeNode *r);

    bool isSymmetricIter(TreeNode *root);
};

#endif // SYMMETRIC_TREE_HPP_
