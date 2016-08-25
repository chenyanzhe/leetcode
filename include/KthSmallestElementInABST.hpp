#ifndef KTH_SMALLEST_ELEMENT_IN_A_BST_HPP_
#define KTH_SMALLEST_ELEMENT_IN_A_BST_HPP_

#include "TreeNode.hpp"

class KthSmallestElementInABST {
public:
    int kthSmallest(TreeNode *root, int k);

private:
    int countNodes(TreeNode *root);

    int kthSmallestBinarySearch(TreeNode *root, int k);

    int kthSmallestIterative(TreeNode *root, int k);

    int kthSmallestRecursive(TreeNode *root, int k);

    void kthSmallestRecursive_helper(TreeNode *root, int &k, int &ret);
};

#endif // KTH_SMALLEST_ELEMENT_IN_A_BST_HPP_
