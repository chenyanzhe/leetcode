#include "catch.hpp"

#include "LowestCommonAncestorOfABinaryTree.hpp"

TEST_CASE("Lowest Common Ancestor of a Binary Tree")
{
  LowestCommonAncestorOfABinaryTree s;
  TreeNode* root = nullptr;
  SECTION("Sample test") {
    TreeNode* _7 = new TreeNode(7);
    TreeNode* _4 = new TreeNode(4);
    TreeNode* _6 = new TreeNode(6);
    TreeNode* _2 = new TreeNode(2, _7, _4);
    TreeNode* _0 = new TreeNode(0);
    TreeNode* _8 = new TreeNode(8);
    TreeNode* _5 = new TreeNode(5, _6, _2);
    TreeNode* _1 = new TreeNode(1, _0, _8);
    TreeNode* _3 = new TreeNode(3, _5, _1);
    root = _3;
    REQUIRE(s.lowestCommonAncestor(root, _5, _1) == _3);
  }
}
