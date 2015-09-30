#include "catch.hpp"

#include "BinaryTreeLevelOrderTraversalII.hpp"

TEST_CASE("Binary Tree Level Order Traversal II") {
	BinaryTreeLevelOrderTraversalII s;

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

	    vector<vector<int>> expected {
	    	{15, 7},
	    	{9, 20},
	    	{3}
	    };

	    REQUIRE(s.levelOrderBottom(root) == expected);
	}

	tree_free(root);
}