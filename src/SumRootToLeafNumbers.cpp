#include "SumRootToLeafNumbers.hpp"

int SumRootToLeafNumbers::sumNumbers(TreeNode *root) {
    if (root == nullptr)
        return 0;

    return sumNumbersRec(root, 0);
}

int SumRootToLeafNumbers::sumNumbersRec(TreeNode *node, int n) {
    if (node->left == nullptr && node->right == nullptr)
        return n * 10 + node->val;

    int ret = 0;

    if (node->left != nullptr)
        ret += sumNumbersRec(node->left, n * 10 + node->val);

    if (node->right != nullptr)
        ret += sumNumbersRec(node->right, n * 10 + node->val);

    return ret;
}
