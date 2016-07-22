#ifndef BINARY_TREE_ZIGZAG_LEVEL_ORDER_TRAVERSAL_HPP_
#define BINARY_TREE_ZIGZAG_LEVEL_ORDER_TRAVERSAL_HPP_

#include "TreeNode.hpp"

#include <vector>

using namespace std;

class BinaryTreeZigzagLevelOrderTraversal {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root);
};

#endif // BINARY_TREE_ZIGZAG_LEVEL_ORDER_TRAVERSAL_HPP_
