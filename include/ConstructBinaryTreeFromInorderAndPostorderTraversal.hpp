#ifndef CONSTRUCT_BINARY_TREE_FROM_INORDER_AND_POSTORDER_TRAVERSAL_HPP_
#define CONSTRUCT_BINARY_TREE_FROM_INORDER_AND_POSTORDER_TRAVERSAL_HPP_

#include "TreeNode.hpp"

#include <vector>

using namespace std;

class ConstructBinaryTreeFromInorderAndPostorderTraversal {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder);

private:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, int inStart, int inEnd, int &postIndex);
};

#endif // CONSTRUCT_BINARY_TREE_FROM_INORDER_AND_POSTORDER_TRAVERSAL_HPP_
