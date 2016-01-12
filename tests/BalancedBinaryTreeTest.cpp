#include "catch.hpp"

#include "BalancedBinaryTree.hpp"

TEST_CASE("Balanced Binary Tree")
{
  BalancedBinaryTree s;
  TreeNode* l1 = nullptr;
  TreeNode* r1 = nullptr;
  SECTION("Sample test") {
    //   1
    //  / \
    // 2   3
    //    / \
    //   5   6
    TreeNode* l5 = new TreeNode(5);
    TreeNode* l6 = new TreeNode(6);
    TreeNode* l2 = new TreeNode(2);
    TreeNode* l3 = new TreeNode(3, l5, l6);
    l1 = new TreeNode(1, l2, l3);
    REQUIRE(s.isBalanced(l1));
    //  1
    //   \
    //    3
    //   / \
    //  5   6
    TreeNode* r5 = new TreeNode(5);
    TreeNode* r6 = new TreeNode(6);
    TreeNode* r3 = new TreeNode(3, r5, r6);
    r1 = new TreeNode(1, nullptr, r3);
    REQUIRE_FALSE(s.isBalanced(r1));
  }
  tree_free(l1);
  tree_free(r1);
}
