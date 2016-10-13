#ifndef SUM_OF_LEFT_LEAVES_HPP_
#define SUM_OF_LEFT_LEAVES_HPP_

#include "TreeNode.hpp"

class SumOfLeftLeaves {
public:
    int sumOfLeftLeaves(TreeNode *root);
private:
    int sumOfLeftLeaves_Recursive(TreeNode *root);
    int sumOfLeftLeaves_Iterative(TreeNode *root);
};

#endif // SUM_OF_LEFT_LEAVES_HPP_