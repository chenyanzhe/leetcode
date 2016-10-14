#ifndef CLOSEST_BINARY_SEARCH_TREE_VALUE_II_HPP_
#define CLOSEST_BINARY_SEARCH_TREE_VALUE_II_HPP_

#include "TreeNode.hpp"

#include <vector>

using namespace std;

class ClosestBinarySearchTreeValueII {
public:
    vector<int> closestKValues(TreeNode *root, double target, int k);
};

#endif // CLOSEST_BINARY_SEARCH_TREE_VALUE_II_HPP_