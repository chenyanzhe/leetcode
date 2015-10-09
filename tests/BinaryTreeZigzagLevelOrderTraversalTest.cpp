#include "catch.hpp"

#include "BinaryTreeZigzagLevelOrderTraversal.hpp"

TEST_CASE("Binary Tree Zigzag Level Order Traversal") {
	BinaryTreeZigzagLevelOrderTraversal s;

	TreeNode *root;

	SECTION("Sample test") {
		//   3
		//  / \
		// 9   20
		//    / \
		//   15  7
		TreeNode *l15 = new TreeNode(15);
		TreeNode *l7  = new TreeNode(7);
		TreeNode *l20 = new TreeNode(20, l15, l7);
		TreeNode *l9  = new TreeNode(9);
		root = new TreeNode(3, l9, l20);

		vector<vector<int>> expected {{3}, {20, 9}, {15, 7}};

		REQUIRE(s.zigzagLevelOrder(root) == expected);
	}

	SECTION("Sample test 2") {
		//     1
		//    / \
		//   2   3
		//  /     \
		// 4       5
		TreeNode *l4 = new TreeNode(4);
		TreeNode *l5  = new TreeNode(5);
		TreeNode *l2 = new TreeNode(2, l4, nullptr);
		TreeNode *l3  = new TreeNode(3, nullptr, l5);
		root = new TreeNode(1, l2, l3);

		vector<vector<int>> expected {{1}, {3, 2}, {4, 5}};

		REQUIRE(s.zigzagLevelOrder(root) == expected);
	}

	tree_free(root);
}