#include "catch.hpp"

#include "BinaryTreePaths.hpp"

#include <algorithm>
using namespace std;

TEST_CASE("Binary Tree Paths")
{
  BinaryTreePaths s;
  TreeNode* root = nullptr;
  SECTION("Sample test") {
    TreeNode* _5 = new TreeNode(5);
    TreeNode* _2 = new TreeNode(2, nullptr, _5);
    TreeNode* _3 = new TreeNode(3);
    TreeNode* _1 = new TreeNode(1, _2, _3);
    root = _1;
    vector<string> expected {"1->2->5", "1->3"};
    vector<string> result = s.binaryTreePaths(root);
    REQUIRE(result.size() == expected.size());

    for (int i = 0; i < result.size(); i++) {
      REQUIRE_FALSE(find(expected.begin(), expected.end(),
                         result[i]) == expected.end());
    }
  }
  tree_free(root);
}
