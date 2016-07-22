#ifndef BINARY_TREE_RIGHT_SIDE_VIEW_HPP_
#define BINARY_TREE_RIGHT_SIDE_VIEW_HPP_

#include "TreeNode.hpp"

#include <vector>

using namespace std;

class BinaryTreeRightSideView {
public:
    vector<int> rightSideView(TreeNode *root);

private:
    vector<int> rightSideViewLevelOrderTraversal(TreeNode *root);

    void rightSideViewPreOrderTraversal(TreeNode *root, int level,
                                        vector<int> &res);
};

#endif // BINARY_TREE_RIGHT_SIDE_VIEW_HPP_
