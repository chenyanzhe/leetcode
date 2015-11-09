#include "catch.hpp"

#include "SumRootToLeafNumbers.hpp"

TEST_CASE("Sum Root to Leaf Numbers") {
    SumRootToLeafNumbers s;

    TreeNode *root = nullptr;

    SECTION("Sample test") {
        /*
         *    1
         *   / \
         *  2   3
         */
        TreeNode *_2 = new TreeNode(2);
        TreeNode *_3 = new TreeNode(3);
        TreeNode *_1 = new TreeNode(1, _2, _3);
        root = _1;

        // 12 + 13
        REQUIRE(s.sumNumbers(root) == 25);
    }

    SECTION("Normal test") {
        /*
         *         5
         *       /   \
         *      4     8
         *     /     / \
         *    1     3   4
         *   / \       / \
         *  7   2     5   1
         */
        TreeNode *_7 = new TreeNode(7);
        TreeNode *_2 = new TreeNode(2);
        TreeNode *_5 = new TreeNode(5);
        TreeNode *_1 = new TreeNode(1);
        TreeNode *_1_2 = new TreeNode(1, _7, _2);
        TreeNode *_3 = new TreeNode(3);
        TreeNode *_4 = new TreeNode(4, _5, _1);
        TreeNode *_4_2 = new TreeNode(4, _1_2, nullptr);
        TreeNode *_8 = new TreeNode(8, _3, _4);
        TreeNode *_5_2 = new TreeNode(5, _4_2, _8);
        root = _5_2;

        // 5417 + 5412 + 583 + 5845 + 5841
        REQUIRE(s.sumNumbers(root) == 23098);
    }

    tree_free(root);
}
