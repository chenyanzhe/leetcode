#include "catch.hpp"

#include "MaximumDepthOfBinaryTree.hpp"

TEST_CASE("Maximum Depth of Binary Tree") {
    MaximumDepthOfBinaryTree s;
    TreeNode *l1 = nullptr;
    SECTION("Sample test") {
        //   1
        //  / \
    // 2   3
        //  \ / \
    //  4 5  6
        TreeNode *l4 = new TreeNode(4);
        TreeNode *l5 = new TreeNode(5);
        TreeNode *l6 = new TreeNode(6);
        TreeNode *l2 = new TreeNode(2, nullptr, l4);
        TreeNode *l3 = new TreeNode(3, l5, l6);
        l1 = new TreeNode(1, l2, l3);
        REQUIRE(s.maxDepth(l1) == 3);
    }
    tree_free(l1);
}
