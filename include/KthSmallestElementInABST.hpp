#ifndef KTH_SMALLEST_ELEMENT_IN_A_BST_HPP_
#define KTH_SMALLEST_ELEMENT_IN_A_BST_HPP_

#include "TreeNode.hpp"

class KthSmallestElementInABST {
public:
    int kthSmallest(TreeNode* root, int k);
private:
    void inOrderSearch(TreeNode* root, int k);
    int cnt;
    int result;
};

#endif // KTH_SMALLEST_ELEMENT_IN_A_BST_HPP_
