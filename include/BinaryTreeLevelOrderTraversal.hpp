#ifndef BINARY_TREE_LEVEL_ORDER_TRAVERSAL_HPP_
#define BINARY_TREE_LEVEL_ORDER_TRAVERSAL_HPP_

#include <vector>

using namespace std;

#include "TreeNode.hpp"

class BinaryTreeLevelOrderTraversal {
public:
    vector<vector<int>> levelOrder(TreeNode *root);
};

#endif // BINARY_TREE_LEVEL_ORDER_TRAVERSAL_HPP_
