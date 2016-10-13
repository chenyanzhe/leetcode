#include "catch.hpp"

#include "BinaryTreeLongestConsecutiveSequence.hpp"

TEST_CASE("Binary Tree Longest Consecutive Sequence") {
    BinaryTreeLongestConsecutiveSequence s;
    TreeNode *root = nullptr;
    SECTION("Sample test I") {
        /*
         * Create a tree like this:
         *     1
         *      \
         *      3
         *     / \
         *    2  4
         *        \
         *        5
         */
        TreeNode *_5 = new TreeNode(5);
        TreeNode *_4 = new TreeNode(4, nullptr, _5);
        TreeNode *_2 = new TreeNode(2);
        TreeNode *_3 = new TreeNode(3, _2, _4);
        TreeNode *_1 = new TreeNode(1, nullptr, _3);
        root = _1;
        REQUIRE(s.longestConsecutive(root) == 3);
    }
    SECTION("Sample test II") {
        /*
         * Create a tree like this:
         *        2
         *         \
         *          3
         *         /
         *        2
         *       /
         *      1
         */
        TreeNode *_1 = new TreeNode(1);
        TreeNode *_2 = new TreeNode(2, _1, nullptr);
        TreeNode *_3 = new TreeNode(3, _2, nullptr);
        TreeNode *_2_2 = new TreeNode(2, nullptr, _3);
        root = _2_2;
        REQUIRE(s.longestConsecutive(root) == 2);
    }
    tree_free(root);
}
