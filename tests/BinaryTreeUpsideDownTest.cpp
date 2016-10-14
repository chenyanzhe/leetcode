#include "catch.hpp"

#include "BinaryTreeUpsideDown.hpp"

TEST_CASE("Binary Tree Upside Down") {
    BinaryTreeUpsideDown s;
    TreeNode *root = nullptr;
    SECTION("Sample test") {
        /*
         * Create a tree like this:
         *      1
         *     / \
         *    2   3
         *   / \
         *  4   5
         */
        TreeNode *_5 = new TreeNode(5);
        TreeNode *_4 = new TreeNode(4);
        TreeNode *_2 = new TreeNode(2, _4, _5);
        TreeNode *_3 = new TreeNode(3);
        TreeNode *_1 = new TreeNode(1, _2, _3);
        root = _1;

        root = s.upsideDownBinaryTree(root);

        /*
         * Should be:
         *      4
         *     / \
         *    5   2
         *       / \
         *      3   1
         */
        REQUIRE_FALSE(root == nullptr);
        REQUIRE(root->val == 4);
        REQUIRE_FALSE(root->left == nullptr);
        REQUIRE(root->left->val == 5);
        REQUIRE(root->left->left == nullptr);
        REQUIRE(root->left->right == nullptr);
        TreeNode *n = root->right;
        REQUIRE_FALSE(n == nullptr);
        REQUIRE(n->val == 2);
        REQUIRE_FALSE(n->left == nullptr);
        REQUIRE(n->left->val == 3);
        REQUIRE(n->left->left == nullptr);
        REQUIRE(n->left->right == nullptr);
        REQUIRE_FALSE(n->right == nullptr);
        REQUIRE(n->right->val == 1);
        REQUIRE(n->right->left == nullptr);
        REQUIRE(n->right->right == nullptr);
    }
    tree_free(root);
}
