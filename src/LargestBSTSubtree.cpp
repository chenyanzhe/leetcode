#include "LargestBSTSubtree.hpp"

#include <climits>

using namespace std;

int LargestBSTSubtree::largestBSTSubtree(TreeNode *root) {
    Result r = helper(root);
    return r.size;
}

LargestBSTSubtree::Result LargestBSTSubtree::helper(TreeNode *root) {
    if (root == nullptr) return Result(true, 0, INT_MAX, INT_MIN);

    Result lr = helper(root->left);
    Result rr = helper(root->right);

    bool isBST = lr.isBST && rr.isBST && root->val > lr.max && root->val < rr.min;
    if (isBST)
        return Result(true, lr.size + rr.size + 1, lr.size ? lr.min : root->val, rr.size ? rr.max : root->val);
    else
        return Result(false, max(lr.size, rr.size), 0, 0);
}