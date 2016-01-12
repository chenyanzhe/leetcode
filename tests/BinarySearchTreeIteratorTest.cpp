#include "catch.hpp"

#include "BinarySearchTreeIterator.hpp"

TEST_CASE("Binary Search Tree Iterator")
{
  TreeNode* root = nullptr;
  SECTION("Sample test") {
    /*
           3
          / \
         2   5
        /   / \
       1   4   6
    */
    TreeNode* _1 = new TreeNode(1);
    TreeNode* _4 = new TreeNode(4);
    TreeNode* _6 = new TreeNode(6);
    TreeNode* _2 = new TreeNode(2, _1, nullptr);
    TreeNode* _5 = new TreeNode(5, _4, _6);
    TreeNode* _3 = new TreeNode(3, _2, _5);
    root = _3;
    BSTIterator i = BSTIterator(root);
    int expected = 1;

    while (i.hasNext()) {
      REQUIRE(i.next() == expected++);
    }
  }
  tree_free(root);
}
