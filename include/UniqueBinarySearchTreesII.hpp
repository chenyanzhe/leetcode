#ifndef UNIQUE_BINARY_SEARCH_TREES_II_HPP_
#define UNIQUE_BINARY_SEARCH_TREES_II_HPP_

#include "TreeNode.hpp"
#include <vector>

using namespace std;

class UniqueBinarySearchTreesII {
public:
    vector<TreeNode *> generateTrees(int n);

private:
    vector<TreeNode *> generateTreesDP(int n);

    vector<TreeNode *> generateTreesRec(int begin, int end);
};

#endif // UNIQUE_BINARY_SEARCH_TREES_II_HPP_
