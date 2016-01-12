#include "catch.hpp"

#include "CountCompleteTreeNodes.hpp"

TEST_CASE("Count Complete Tree Nodes")
{
  CountCompleteTreeNodes s;
  TreeNode* root = nullptr;
  SECTION("Sample test") {
    TreeNode* _4 = new TreeNode(4);
    TreeNode* _5 = new TreeNode(5);
    TreeNode* _6 = new TreeNode(6);
    TreeNode* _2 = new TreeNode(2, _4, _5);
    TreeNode* _3 = new TreeNode(3, _6, nullptr);
    TreeNode* _1 = new TreeNode(1, _2, _3);
    root = _1;
    REQUIRE(s.countNodes(root) == 6);
  }
  tree_free(root);
}
