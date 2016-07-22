#include "catch.hpp"

#include "RecoverBinarySearchTree.hpp"

TEST_CASE("Recover Binary Search Tree") {
    RecoverBinarySearchTree s;
    TreeNode *root = nullptr;
    SECTION("Sample test") {
        /*
         * node 4 and node 6 are swapped:
           *       5
           *     /   \
           *    3     8
           *   / \   / \
           *  1   6  4  9
           */
        TreeNode *_1 = new TreeNode(1);
        TreeNode *_4 = new TreeNode(4);
        TreeNode *_6 = new TreeNode(6);
        TreeNode *_9 = new TreeNode(9);
        TreeNode *_3 = new TreeNode(3, _1, _6);
        TreeNode *_8 = new TreeNode(8, _4, _9);
        TreeNode *_5 = new TreeNode(5, _3, _8);
        root = _5;
        s.recoverTree(root);
        /*
         * after recover should be:
         *       5
         *     /   \
         *    3     8
         *   / \   / \
         *  1   4  6  9
         */
        string expected = "5 3 1 # # 4 # # 8 6 # # 9 # # ";
        REQUIRE(tree_serialize(root) == expected);
    }
    tree_free(root);
}
