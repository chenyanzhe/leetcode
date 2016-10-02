#include "SumOfLeftLeaves.hpp"

#include <queue>

using namespace std;

int SumOfLeftLeaves::sumOfLeftLeaves(TreeNode *root) {
    queue<TreeNode *> left;
    queue<TreeNode *> right;

    int ret = 0;
    if (root) right.push(root);

    while (!left.empty() || !right.empty()) {
        int ln = left.size();
        int rn = right.size();
        while (ln--) {
            TreeNode *n = left.front();
            left.pop();
            if (n->left || n->right) {
                if (n->left) left.push(n->left);
                if (n->right) right.push(n->right);
            } else
                ret += n->val;
        }
        while (rn--) {
            TreeNode *n = right.front();
            right.pop();
            if (n->left) left.push(n->left);
            if (n->right) right.push(n->right);
        }
    }

    return ret;
}