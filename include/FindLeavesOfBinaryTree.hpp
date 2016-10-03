#ifndef FIND_LEAVES_OF_BINARY_TREE_HPP_
#define FIND_LEAVES_OF_BINARY_TREE_HPP_

#include "TreeNode.hpp"

#include <vector>

using namespace std;

class FindLeavesOfBinaryTree {
public:
    vector<vector<int>> findLeaves(TreeNode *root);

private:
    int height(TreeNode *root, vector<vector<int>> &ret);
};

#endif // FIND_LEAVES_OF_BINARY_TREE_HPP_