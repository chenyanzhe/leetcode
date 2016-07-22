#ifndef RECOVER_BINARY_SEARCH_TREE_HPP_
#define RECOVER_BINARY_SEARCH_TREE_HPP_

#include "TreeNode.hpp"

class RecoverBinarySearchTree {
public:
    void recoverTree(TreeNode *root);

private:
    void findSegments(TreeNode *root, TreeNode *&prev, TreeNode *&first,
                      TreeNode *&second);
};

#endif // RECOVER_BINARY_SEARCH_TREE_HPP_
