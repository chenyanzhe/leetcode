#include "BinaryTreeInorderTraversal.hpp"

#include <stack>
#include <unordered_map>

using namespace std;

vector<int> BinaryTreeInorderTraversal::inorderTraversal(TreeNode *root) {
    return inorderTraversal_HashTable(root);
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

vector<int> BinaryTreeInorderTraversal::inorderTraversal_HashTable(TreeNode *root) {
    vector<int> ret;
    unordered_map<TreeNode *, int> action;
    stack<TreeNode *> s;

    if (root == nullptr)
        return ret;

    if (root->right) {
        s.push(root->right);
        action[root->right] = 0;
    }
    s.push(root);
    action[root] = 1;
    if (root->left) {
        s.push(root->left);
        action[root->left] = 0;
    }

    while (!s.empty()) {
        TreeNode *node = s.top();
        s.pop();
        if (action[node] == 1) {
            ret.push_back(node->val);
            action.erase(node);
        } else {
            if (node->right) {
                s.push(node->right);
                action[node->right] = 0;
            }
            s.push(node);
            action[node] = 1;
            if (node->left) {
                s.push(node->left);
                action[node->left] = 0;
            }
        }
    }

    return ret;
}