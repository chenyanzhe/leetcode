#include "BinaryTreePostorderTraversal.hpp"

#include <stack>

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

