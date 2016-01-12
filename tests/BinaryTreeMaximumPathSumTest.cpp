#include "catch.hpp"

#include "BinaryTreeMaximumPathSum.hpp"

TEST_CASE("Binary Tree Maximum Path Sum")
{
  BinaryTreeMaximumPathSum s;
  TreeNode* root = nullptr;
  SECTION("Sample test") {
    //   1
    //  / \
    // 2   3
    TreeNode* l2 = new TreeNode(2);
    TreeNode* l3 = new TreeNode(3);
    root = new TreeNode(1, l2, l3);
    REQUIRE(s.maxPathSum(root) == 6);
  }
  tree_free(root);
}
