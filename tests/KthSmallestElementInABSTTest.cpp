#include "catch.hpp"

#include "KthSmallestElementInABST.hpp"

TEST_CASE("Kth Smallest Element in a BST") {
    KthSmallestElementInABST s;
    TreeNode *root = nullptr;
    SECTION("Sample test") {
        //   2
        //  / \
        // 1   3
        TreeNode *l1 = new TreeNode(1);
        TreeNode *l3 = new TreeNode(3);
        root = new TreeNode(2, l1, l3);
        REQUIRE(s.kthSmallest(root, 1) == 1);
        REQUIRE(s.kthSmallest(root, 2) == 2);
        REQUIRE(s.kthSmallest(root, 3) == 3);
    }
    tree_free(root);
}
