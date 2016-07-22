#ifndef SUM_ROOT_TO_LEAF_NUMBERS_HPP_
#define SUM_ROOT_TO_LEAF_NUMBERS_HPP_

#include "TreeNode.hpp"

class SumRootToLeafNumbers {
public:
    int sumNumbers(TreeNode *root);

private:
    int sumNumbersRec(TreeNode *root, int n);
};

#endif // SUM_ROOT_TO_LEAF_NUMBERS_HPP_
