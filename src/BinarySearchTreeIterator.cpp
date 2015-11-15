#include "BinarySearchTreeIterator.hpp"

BSTIterator::BSTIterator(TreeNode *root)
{
    this->root = root;
    while (root != nullptr) {
        s.push(root);
        root = root->left;
    }
}

bool BSTIterator::hasNext()
{
    return !s.empty();
}

int BSTIterator::next()
{
    TreeNode *n = s.top();
    s.pop();
    int ret = n->val;
    n = n->right;
    while (n != nullptr) {
        s.push(n);
        n = n->left;
    }
    return ret;
}
