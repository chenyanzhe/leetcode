#ifndef COUNT_UNIVALUE_SUBTREES_HPP_
#define COUNT_UNIVALUE_SUBTREES_HPP_

#include "TreeNode.hpp"

class CountUnivalueSubtrees {
public:
    int countUnivalSubtrees(TreeNode *root);

private:
    bool isUnival(TreeNode *root, int &global);
};

#endif // COUNT_UNIVALUE_SUBTREES_HPP_