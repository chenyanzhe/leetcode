#include "catch.hpp"

#include "FindLeavesOfBinaryTree.hpp"

TEST_CASE("Find Leaves of Binary Tree") {
    FindLeavesOfBinaryTree s;
    TreeNode *root = nullptr;
    SECTION("Sample test") {
        /*
         *      1
         *     / \
         *    2  3
         *   / \
         *  4  5
         */
        TreeNode *_4 = new TreeNode(4);
        TreeNode *_5 = new TreeNode(5);
        TreeNode *_2 = new TreeNode(2, _4, _5);
        TreeNode *_3 = new TreeNode(3);
        TreeNode *_1 = new TreeNode(1, _2, _3);
        root = _1;
        vector<vector<int>> expected{{4, 5, 3},
                                     {2},
                                     {1}};
        REQUIRE(s.findLeaves(root) == expected);
    }
    tree_free(root);
}
