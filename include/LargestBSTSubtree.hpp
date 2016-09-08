#ifndef LARGEST_BST_SUBTREE_HPP_
#define LARGEST_BST_SUBTREE_HPP_

#include "TreeNode.hpp"

class LargestBSTSubtree {
public:
    int largestBSTSubtree(TreeNode *root);

private:
    struct Result {
        bool isBST;
        int size;
        int min;
        int max;

        Result(bool ib, int sz, int min, int max) : isBST(ib), size(sz), min(min), max(max) {}
    };

    Result helper(TreeNode *root);
};

#endif // LARGEST_BST_SUBTREE_HPP_