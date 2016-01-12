#include "catch.hpp"

#include "ValidateBinarySearchTree.hpp"

TEST_CASE("Validate Binary Search Tree")
{
  ValidateBinarySearchTree s;
  TreeNode* root = nullptr;
  SECTION("Sample test 1") {
    /*
       *       5
       *     /   \
       *    3     8
       *   / \   / \
       *  1   4  6  9
       */
    TreeNode* _1 = new TreeNode(1);
    TreeNode* _4 = new TreeNode(4);
    TreeNode* _6 = new TreeNode(6);
    TreeNode* _9 = new TreeNode(9);
    TreeNode* _3 = new TreeNode(3, _1, _4);
    TreeNode* _8 = new TreeNode(8, _6, _9);
    TreeNode* _5 = new TreeNode(5, _3, _8);
    root = _5;
    REQUIRE(s.isValidBST(root));
  }
  SECTION("Sample test 2") {
    /*
       *       5
       *     /   \
       *    3     8
       *   / \   / \
       *  1   2  6  9
       */
    TreeNode* _1 = new TreeNode(1);
    TreeNode* _2 = new TreeNode(2);
    TreeNode* _6 = new TreeNode(6);
    TreeNode* _9 = new TreeNode(9);
    TreeNode* _3 = new TreeNode(3, _1, _2);
    TreeNode* _8 = new TreeNode(8, _6, _9);
    TreeNode* _5 = new TreeNode(5, _3, _8);
    root = _5;
    REQUIRE_FALSE(s.isValidBST(root));
  }
  tree_free(root);
}
