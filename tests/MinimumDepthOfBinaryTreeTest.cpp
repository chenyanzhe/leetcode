#include "catch.hpp"

#include "MinimumDepthOfBinaryTree.hpp"

TEST_CASE("Minimum Depth of Binary Tree")
{
  MinimumDepthOfBinaryTree s;
  TreeNode* l = nullptr;
  SECTION("Sample test") {
    //     1
    //    / \
    //   2   2
    //      /
    //     3
    TreeNode* l3 = new TreeNode(3);
    TreeNode* l2_1 = new TreeNode(2);
    TreeNode* l2_2 = new TreeNode(2, l3, nullptr);
    l = new TreeNode(1, l2_1, l2_2);
    REQUIRE(s.minDepth(l) == 2);
  }
  tree_free(l);
}
