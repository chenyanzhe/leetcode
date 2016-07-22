#ifndef CONSTRUCT_BINARY_TREE_FROM_PREORDER_AND_INORDER_TRAVERSAL_HPP_
#define CONSTRUCT_BINARY_TREE_FROM_PREORDER_AND_INORDER_TRAVERSAL_HPP_

#include "TreeNode.hpp"

#include <vector>

using namespace std;

class ConstructBinaryTreeFromPreorderAndInorderTraversal {
private:
    int preIndex;
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder);

private:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int inStart,
                        int inEnd);
};

#endif // CONSTRUCT_BINARY_TREE_FROM_PREORDER_AND_INORDER_TRAVERSAL_HPP_
