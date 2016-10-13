#ifndef BINARY_TREE_LONGEST_CONSECUTIVE_SEQUENCE_HPP_
#define BINARY_TREE_LONGEST_CONSECUTIVE_SEQUENCE_HPP_

#include "TreeNode.hpp"

class BinaryTreeLongestConsecutiveSequence {
public:
    int longestConsecutive(TreeNode *root);

private:
    void dfs(TreeNode *root, int cur, int target, int &global);
};

#endif // BINARY_TREE_LONGEST_CONSECUTIVE_SEQUENCE_HPP_