#include "catch.hpp"

#include "TreeNode.hpp"

TEST_CASE("Tree Node") {
  TreeNode *root = nullptr;

  SECTION("Normal test") {
    /*
     * Create a tree like this:
     *    30
     *    / \
     *  10   20
     *  /    / \
     * 50   45 35
     *
     * The serialize result should be:
     * 30 10 50 # # # 20 45 # # 35 # #
     */
    TreeNode *_50 = new TreeNode(50);
    TreeNode *_45 = new TreeNode(45);
    TreeNode *_35 = new TreeNode(35);
    TreeNode *_10 = new TreeNode(10, _50, nullptr);
    TreeNode *_20 = new TreeNode(20, _45, _35);
    TreeNode *_30 = new TreeNode(30, _10, _20);
    root = _30;

    string expected = "30 10 50 # # # 20 45 # # 35 # # ";
    REQUIRE(tree_serialize(root) == expected);
  }

  tree_free(root);
}
