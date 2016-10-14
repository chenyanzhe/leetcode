#include "catch.hpp"

#include "CountUnivalueSubtrees.hpp"

TEST_CASE("Count Univalue Subtrees") {
    CountUnivalueSubtrees s;
    TreeNode *root = nullptr;
    SECTION("Sample test") {
        /*
         * Create a tree like this:
         *      5
         *     / \
         *    1   5
         *   / \   \
         *  5  5    5
         */
        TreeNode *_5_1 = new TreeNode(5);
        TreeNode *_5_2 = new TreeNode(5);
        TreeNode *_5_3 = new TreeNode(5);
        TreeNode *_1 = new TreeNode(1, _5_1, _5_2);
        TreeNode *_5_4 = new TreeNode(5, nullptr, _5_3);
        TreeNode *_5_5 = new TreeNode(5, _1, _5_4);
        root = _5_5;

        REQUIRE(s.countUnivalSubtrees(root) == 4);
    }
    tree_free(root);
}
