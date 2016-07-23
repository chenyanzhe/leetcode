#ifndef BINARY_TREE_INORDER_TRAVERSAL_HPP_
#define BINARY_TREE_INORDER_TRAVERSAL_HPP_

#include "TreeNode.hpp"

#include <vector>

using namespace std;

class BinaryTreeInorderTraversal {
public:
    vector<int> inorderTraversal(TreeNode *root);

private:
    vector<int> inorderTraversal_Stack(TreeNode *root);

    vector<int> inorderTraversal_Morris(TreeNode *root);

    vector<int> inorderTraversal_HashTable(TreeNode *root);
};

#endif // BINARY_TREE_INORDER_TRAVERSAL_HPP_
