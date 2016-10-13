#include "SumOfLeftLeaves.hpp"

#include <stack>

using namespace std;

int SumOfLeftLeaves::sumOfLeftLeaves(TreeNode *root) {
    return sumOfLeftLeaves_Recursive(root);
}

int SumOfLeftLeaves::sumOfLeftLeaves_Recursive(TreeNode *root) {
    if (root == nullptr) return 0;
    int ans = 0;
    if (root->left) {
        if (root->left->left == nullptr && root->left->right == nullptr)
            ans += root->left->val;
        else
            ans += sumOfLeftLeaves_Recursive(root->left);
    }
    if (root->right)
        ans += sumOfLeftLeaves_Recursive(root->right);
    return ans;
}

int SumOfLeftLeaves::sumOfLeftLeaves_Iterative(TreeNode *root) {
    if (root == nullptr) return 0;
    int ans = 0;
    stack<TreeNode *> s;
    s.push(root);
    while (!s.empty()) {
        TreeNode *n = s.top();
        if (n->left) {
            if (n->left->left == nullptr && n->left->right == nullptr)
                ans += n->left->val;
            else
                s.push(n->left);
        }
        if (n->right) {
            if (n->right->left || n->right->right)
                s.push(n->right);
        }
    }
    return ans;
}