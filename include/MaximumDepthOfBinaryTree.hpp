#ifndef MAXIMUM_DEPTH_OF_BINARY_TREE_HPP_
#define MAXIMUM_DEPTH_OF_BINARY_TREE_HPP_

#include "TreeNode.hpp"

class MaximumDepthOfBinaryTree {
public:
    int maxDepth(TreeNode *root);

private:
    int maxDepthRecursive(TreeNode *root);

    int maxDepthIterative(TreeNode *root);
};

#endif // MAXIMUM_DEPTH_OF_BINARY_TREE_HPP_
