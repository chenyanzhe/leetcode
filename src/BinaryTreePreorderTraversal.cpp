#include "BinaryTreePreorderTraversal.hpp"

#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> BinaryTreePreorderTraversal::preorderTraversal(TreeNode *root) {
    return preorderTraversal_Queue(root);
}

vector<int> BinaryTreePreorderTraversal::preorderTraversal_Stack(TreeNode *root) {
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

vector<int> BinaryTreePreorderTraversal::preorderTraversal_Queue(TreeNode *root) {
    vector<int> ret;
    queue<TreeNode *> q;

    if (root != nullptr) q.push(root);

    while (!q.empty()) {
        TreeNode *current = q.front();
        q.pop();
        ret.push_back(current->val);

        if (current->left != nullptr)
            q.push(current->left);

        if (current->right != nullptr)
            q.push(current->right);
    }

    return ret;
}

vector<int> BinaryTreePreorderTraversal::preorderTraversal_Morris(TreeNode *root) {
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

vector<int> BinaryTreePreorderTraversal::preorderTraversal_HashTable(TreeNode *root) {
    vector<int> ret;
    unordered_map<TreeNode *, int> action;
    stack<TreeNode *> s;

    if (root == nullptr)
        return ret;

    if (root->right) {
        s.push(root->right);
        action[root->right] = 0;
    }
    if (root->left) {
        s.push(root->left);
        action[root->left] = 0;
    }
    s.push(root);
    action[root] = 1;

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
            if (node->left) {
                s.push(node->left);
                action[node->left] = 0;
            }
            s.push(node);
            action[node] = 1;
        }
    }

    return ret;
}
