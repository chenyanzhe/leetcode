#ifndef BINARY_TREE_PATHS_HPP_
#define BINARY_TREE_PATHS_HPP_

#include <vector>
#include <string>

#include "TreeNode.hpp"

using namespace std;

class BinaryTreePaths {
public:
    vector<string> binaryTreePaths(TreeNode *root);

private:
    void dfs(TreeNode *root, string path, vector<string> &ret);
};

#endif // BINARY_TREE_PATHS_HPP_