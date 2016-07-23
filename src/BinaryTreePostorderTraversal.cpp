#include "BinaryTreePostorderTraversal.hpp"

#include <stack>
#include <unordered_map>

using namespace std;

vector<int> BinaryTreePostorderTraversal::postorderTraversal(TreeNode *root) {
    return postorderTraversal_OneStack(root);
}

vector<int> BinaryTreePostorderTraversal::postorderTraversal_OneStack(
        TreeNode *root) {
    vector<int> ret;
    stack<TreeNode *> s;
    TreeNode *current = root;

    while (current != nullptr || !s.empty()) {
        if (current != nullptr) {
            s.push(current);
            current = current->left;
        } else {
            TreeNode *temp = s.top()->right;

            if (temp == nullptr) {
                temp = s.top();
                s.pop();
                ret.push_back(temp->val);

                while (!s.empty() && temp == s.top()->right) {
                    temp = s.top();
                    s.pop();
                    ret.push_back(temp->val);
                }
            } else
                current = temp;
        }
    }

    return ret;
}

vector<int> BinaryTreePostorderTraversal::postorderTraversal_TwoStack(
        TreeNode *root) {
    vector<int> ret;
    stack<TreeNode *> s1;
    stack<TreeNode *> s2;

    if (root != nullptr) s1.push(root);

    while (!s1.empty()) {
        TreeNode *current = s1.top();
        s1.pop();
        s2.push(current);

        if (current->left != nullptr)
            s1.push(current->left);

        if (current->right != nullptr)
            s1.push(current->right);
    }

    while (!s2.empty()) {
        TreeNode *current = s2.top();
        s2.pop();
        ret.push_back(current->val);
    }

    return ret;
}

vector<int> BinaryTreePostorderTraversal::postorderTraversal_HashTable(TreeNode *root) {
    vector<int> ret;
    unordered_map<TreeNode *, int> action;
    stack<TreeNode *> s;

    if (root == nullptr)
        return ret;

    s.push(root);
    action[root] = 1;
    if (root->right) {
        s.push(root->right);
        action[root->right] = 0;
    }
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
            s.push(node);
            action[node] = 1;
            if (node->right) {
                s.push(node->right);
                action[node->right] = 0;
            }
            if (node->left) {
                s.push(node->left);
                action[node->left] = 0;
            }
        }
    }

    return ret;
}

