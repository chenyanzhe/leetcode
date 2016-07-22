#ifndef CONVERT_SORTED_ARRAY_TO_BINARY_SEARCH_TREE_HPP_
#define CONVERT_SORTED_ARRAY_TO_BINARY_SEARCH_TREE_HPP_

#include "TreeNode.hpp"

#include <vector>

using namespace std;

class ConvertSortedArrayToBinarySearchTree {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums);

private:
    TreeNode *sortedArrayToBST(vector<int> &nums, int begin, int end);
};

#endif // CONVERT_SORTED_ARRAY_TO_BINARY_SEARCH_TREE_HPP_
