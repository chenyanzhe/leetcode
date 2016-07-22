#include "BinaryTreeInorderTraversal.hpp"

#include <stack>

using namespace std;

vector<int> BinaryTreeInorderTraversal::inorderTraversal(TreeNode *root) {
    return inorderTraversal_Morris(root);
}

vector<int> BinaryTreeInorderTraversal::inorderTraversal_Stack(TreeNode *root) {
    vector<int> ret;
    stack<TreeNode *> s;
    TreeNode *current = root;

    while (!s.empty() || current != nullptr) {
        if (current != nullptr) {
            s.push(current);
            current = current->left;
        } else {
            current = s.top();
            s.pop();
            ret.push_back(current->val);
            current = current->right;
        }
    }

    return ret;
}

vector<int> BinaryTreeInorderTraversal::inorderTraversal_Morris(TreeNode *root) {
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
                pred->right = current;
                current = current->left;
            } else {
                ret.push_back(current->val);
                pred->right = nullptr;
                current = current->right;
            }
        }
    }

    return ret;
}
