#include "catch.hpp"

#include "SumOfLeftLeaves.hpp"

TEST_CASE("Sum of Left Leaves") {
    SumOfLeftLeaves s;
    TreeNode *root = nullptr;
    SECTION("Sample tests") {
        /*
         * Create a tree like this:
         *     3
         *    / \
         *   9  20
         *      / \
         *     15 7
         *
         */
        TreeNode *_15 = new TreeNode(15);
        TreeNode *_7 = new TreeNode(7);
        TreeNode *_20 = new TreeNode(20, _15, _7);
        TreeNode *_9 = new TreeNode(9);
        TreeNode *_3 = new TreeNode(3, _9, _20);
        root = _3;
        REQUIRE(s.sumOfLeftLeaves(root) == 24);
    }
    tree_free(root);
}
