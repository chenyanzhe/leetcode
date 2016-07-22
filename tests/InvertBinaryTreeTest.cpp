#include "catch.hpp"

#include "InvertBinaryTree.hpp"

TEST_CASE("Invert Binary Tree") {
    InvertBinaryTree s;
    TreeNode *root = nullptr;
    SECTION("Sample test") {
        TreeNode *_1 = new TreeNode(1);
        TreeNode *_3 = new TreeNode(3);
        TreeNode *_6 = new TreeNode(6);
        TreeNode *_9 = new TreeNode(9);
        TreeNode *_2 = new TreeNode(2, _1, _3);
        TreeNode *_7 = new TreeNode(7, _6, _9);
        TreeNode *_4 = new TreeNode(4, _2, _7);
        root = _4;
        root = s.invertTree(root);
        REQUIRE(root->val == 4);
        REQUIRE(root->left->val == 7);
        REQUIRE(root->right->val == 2);
        TreeNode *l = root->left;
        TreeNode *r = root->right;
        REQUIRE(l->left->val == 9);
        REQUIRE(l->right->val == 6);
        REQUIRE(r->left->val == 3);
        REQUIRE(r->right->val == 1);
    }
}
