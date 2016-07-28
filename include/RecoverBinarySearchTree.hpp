#ifndef RECOVER_BINARY_SEARCH_TREE_HPP_
#define RECOVER_BINARY_SEARCH_TREE_HPP_

#include "TreeNode.hpp"

#include <utility>

using namespace std;

class RecoverBinarySearchTree {
public:
    void recoverTree(TreeNode *root);

private:
    void recoverTree_Morris(TreeNode *root);

    void detect(pair<TreeNode *, TreeNode *> &broken, TreeNode *prev, TreeNode *current);

    void findSegments(TreeNode *root, TreeNode *&prev, TreeNode *&first,
                      TreeNode *&second);
};

#endif // RECOVER_BINARY_SEARCH_TREE_HPP_
