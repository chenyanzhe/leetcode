#include "BinaryTreePreorderTraversal.hpp"

#include <stack>

using namespace std;

vector<int> BinaryTreePreorderTraversal::preorderTraversal(TreeNode *root) {
    return preorderTraversal_Morris(root);
}

vector<int> BinaryTreePreorderTraversal::preorderTraversal_Stack(
        TreeNode *root) {
    vector<int> ret;
    stack<TreeNode *> s;

    if (root != nullptr) s.push(root);

    while (!s.empty()) {
        TreeNode *current = s.top();
        s.pop();
        ret.push_back(current->val);

        if (current->right != nullptr)
            s.push(current->right);

        if (current->left != nullptr)
            s.push(current->left);
    }

    return ret;
}

vector<int> BinaryTreePreorderTraversal::preorderTraversal_Morris(
        TreeNode *root) {
    vector<int> ret;
    TreeNode *current = root;

    while (current != nullptr) {
        if (current->left == nullptr) {
            ret.push_back(current->val);
            current = current->right;
        } else {
            TreeNode *pred = current->left;

            while (pred->right != nullptr && pred->right != current)
                pred = pred->right;

            if (pred->right == nullptr) {
                ret.push_back(current->val);
                pred->right = current;
                current = current->left;
            } else {
                pred->right = nullptr;
                current = current->right;
            }
        }
    }

    return ret;
}
