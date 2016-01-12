#include "catch.hpp"

#include "ConvertSortedArrayToBinarySearchTree.hpp"

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

TEST_CASE("Convert Sorted Array to Binary Search Tree")
{
  ConvertSortedArrayToBinarySearchTree s;
  TreeNode* root = nullptr;
  SECTION("Sample test") {
    vector<int> nums {1, 2, 3, 4};
    root = s.sortedArrayToBST(nums);
    /*
     *    2                  3
     *   / \                / \
     *  1   3      or      2   4
     *       \            /
     *        4          1
     */
    vector<string> expected {"2 1 # # 3 # 4 # # ", "3 2 1 # 4 # # "};
    REQUIRE_FALSE(find(expected.begin(), expected.end(),
                       tree_serialize(root)) == expected.end());
  }
  tree_free(root);
}
