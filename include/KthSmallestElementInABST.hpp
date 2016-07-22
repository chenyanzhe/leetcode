#ifndef KTH_SMALLEST_ELEMENT_IN_A_BST_HPP_
#define KTH_SMALLEST_ELEMENT_IN_A_BST_HPP_

#include "TreeNode.hpp"

class KthSmallestElementInABST {
public:
    int kthSmallest(TreeNode *root, int k);

private:
    int countNodes(TreeNode *root);

    int kthSmallestIterative(TreeNode *root, int k);
};

#endif // KTH_SMALLEST_ELEMENT_IN_A_BST_HPP_
