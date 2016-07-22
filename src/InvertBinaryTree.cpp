#include "InvertBinaryTree.hpp"

#include <stack>

using namespace std;

TreeNode *InvertBinaryTree::invertTree(TreeNode *root) {
    return invertTreeIterative(root);
}

TreeNode *InvertBinaryTree::invertTreeRecursive(TreeNode *root) {
    if (root == nullptr)
        return nullptr;

    swap(root->left, root->right);
    invertTreeRecursive(root->left);
    invertTreeRecursive(root->right);
    return root;
}

TreeNode *InvertBinaryTree::invertTreeIterative(TreeNode *root) {
    stack<TreeNode *> s;

    if (root != nullptr)
        s.push(root);

    while (!s.empty()) {
        TreeNode *node = s.top();
        s.pop();
        swap(node->left, node->right);

        if (node->left != nullptr)
            s.push(node->left);

        if (node->right != nullptr)
            s.push(node->right);
    }

    return root;
}
