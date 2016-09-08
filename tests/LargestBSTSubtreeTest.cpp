#include "catch.hpp"

#include "LargestBSTSubtree.hpp"

TEST_CASE("Largest BST Subtree") {
    LargestBSTSubtree s;
    TreeNode *root = nullptr;
    SECTION("Sample test") {
        //      10
        //     / \
        //    5  15
        //   / \  \
        //  1  8  7
        TreeNode *l1 = new TreeNode(1);
        TreeNode *l8 = new TreeNode(8);
        TreeNode *l7 = new TreeNode(7);
        TreeNode *l5 = new TreeNode(5, l1, l8);
        TreeNode *l15 = new TreeNode(15, nullptr, l7);
        TreeNode *l10 = new TreeNode(10, l5, l15);
        root = l10;
        REQUIRE(s.largestBSTSubtree(root) == 3);
    }
    tree_free(root);
}
