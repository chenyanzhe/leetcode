#include "catch.hpp"

#include "ClosestBinarySearchTreeValue.hpp"

TEST_CASE("Closest Binary Search Tree Value") {
    ClosestBinarySearchTreeValue s;
    TreeNode *l1 = nullptr;
    SECTION("Sample test") {
        //   1
        //  / \
        // 2   3
        //    / \
        //   5   6
        TreeNode *l5 = new TreeNode(5);
        TreeNode *l6 = new TreeNode(6);
        TreeNode *l2 = new TreeNode(2);
        TreeNode *l3 = new TreeNode(3, l5, l6);
        l1 = new TreeNode(1, l2, l3);
        double target = 2.67;
        REQUIRE(s.closestValue(l1, target) == 3);
    }
    tree_free(l1);
}
