#include "catch.hpp"

#include "BinaryTreeInorderTraversal.hpp"

TEST_CASE("Binary Tree Inorder Traversal") {
	BinaryTreeInorderTraversal s;

	TreeNode *root = nullptr;

	SECTION("Sample test") {
		/*
	     * Create a tree like this:
	     *     3
	     *    / \
	     *   9   20
	     *       / \
	     *      15  7
	     */

        TreeNode *_15 = new TreeNode(15);
	    TreeNode *_7 = new TreeNode(7);
	    TreeNode *_9 = new TreeNode(9);
	    TreeNode *_20 = new TreeNode(20, _15, _7);
	    TreeNode *_3 = new TreeNode(3, _9, _20);
	    root = _3;

	    vector<int> expected { 9, 3, 15, 20, 7 };

	    REQUIRE(s.inorderTraversal(root) == expected);
	}

	tree_free(root);
}
