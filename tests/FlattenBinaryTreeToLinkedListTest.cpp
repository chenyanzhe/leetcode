#include "catch.hpp"

#include "FlattenBinaryTreeToLinkedList.hpp"

TEST_CASE("Flatten Binary Tree to Linked List") {
	FlattenBinaryTreeToLinkedList s;

	TreeNode *root = nullptr;

	SECTION("Sample test") {
		/*
		 *     1
         *    / \
         *   2   5
         *  / \   \
         * 3   4   6
         *
         * after flatten, it should be:
         *
         * 1
         *  \
         *   2
         *    \
         *     3
         *      \
         *       4
         *        \
         *         5
         *          \
         *           6
         */

        TreeNode *_3 = new TreeNode(3);
        TreeNode *_4 = new TreeNode(4);
        TreeNode *_6 = new TreeNode(6);
        TreeNode *_2 = new TreeNode(2, _3, _4);
        TreeNode *_5 = new TreeNode(5, nullptr, _6);
        TreeNode *_1 = new TreeNode(1, _2, _5);
        root = _1;

        s.flatten(root);

        TreeNode *item = root;
        REQUIRE_FALSE(item == nullptr); REQUIRE(item->val == 1); item = item->right;
        REQUIRE_FALSE(item == nullptr); REQUIRE(item->val == 2); item = item->right;
        REQUIRE_FALSE(item == nullptr); REQUIRE(item->val == 3); item = item->right;
        REQUIRE_FALSE(item == nullptr); REQUIRE(item->val == 4); item = item->right;
        REQUIRE_FALSE(item == nullptr); REQUIRE(item->val == 5); item = item->right;
        REQUIRE_FALSE(item == nullptr); REQUIRE(item->val == 6); item = item->right;
        REQUIRE(item == nullptr);
	}

	tree_free(root);
}
