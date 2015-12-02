#include "catch.hpp"

#include "BinaryTreeLevelOrderTraversal.hpp"

TEST_CASE("Binary Tree Level Order Traversal") {
	BinaryTreeLevelOrderTraversal s;

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
	    	{3},
	    	{9, 20},
	    	{15, 7}
	    };

	    REQUIRE(s.levelOrder(root) == expected);
	}

	tree_free(root);
}
