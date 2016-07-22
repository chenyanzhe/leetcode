#include "KthSmallestElementInABST.hpp"

#include <stack>

using namespace std;

int KthSmallestElementInABST::kthSmallest(TreeNode *root, int k) {
    int n = countNodes(root->left);

    if (k <= n)
        return kthSmallest(root->left, k);
    else if (k > n + 1)
        return kthSmallest(root->right, k - n - 1);

    return root->val;
}

int KthSmallestElementInABST::countNodes(TreeNode *root) {
    if (root == nullptr)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int KthSmallestElementInABST::kthSmallestIterative(TreeNode *root, int k) {
    stack<TreeNode *> S;
    TreeNode *current = root;

    while (current != nullptr) {
        S.push(current);
        current = current->left;
    }

    while (k != 0) {
        TreeNode *current = S.top();
        S.pop();
        k--;

        if (k == 0)
            return current->val;

        current = current->right;

        while (current != nullptr) {
            S.push(current);
            current = current->left;
        }
    }

    return -1;
}
