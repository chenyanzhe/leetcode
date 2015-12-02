#include "catch.hpp"

#include "PathSum.hpp"

TEST_CASE("Path Sum") {
	PathSum s;

	TreeNode *root = nullptr;

	SECTION("Sample test") {
		/*
	     *         5
	     *       /   \
	     *      4     8
	     *     /     / \
	     *    11    13  4
	     *   /  \        \
	     *  7    2        1
	     */
	    TreeNode *_7 = new TreeNode(7);
	    TreeNode *_2 = new TreeNode(2);
	    TreeNode *_1 = new TreeNode(1);
	    TreeNode *_11 = new TreeNode(11, _7, _2);
	    TreeNode *_13 = new TreeNode(13);
	    TreeNode *_4 = new TreeNode(4, nullptr, _1);
	    TreeNode *_4_2 = new TreeNode(4, _11, nullptr);
	    TreeNode *_8 = new TreeNode(8, _13, _4);
	    TreeNode *_5 = new TreeNode(5, _4_2, _8);
	    root = _5;

	    // There exist a root-to-leaf path 5->4->11->2 which sum is 22.
	    REQUIRE(s.hasPathSum(root, 22));
	}

	tree_free(root);
}
