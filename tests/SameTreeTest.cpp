#include "catch.hpp"

#include "SameTree.hpp"

TEST_CASE("Same Tree") {
	SameTree s;

	TreeNode *l1 = nullptr;
	TreeNode *r1 = nullptr;

	SECTION("Sample test") {
		//   1
		//  / \
		// 2   3
		//  \ / \
		//  4 5  6
		TreeNode *l4 = new TreeNode(4);
		TreeNode *l5 = new TreeNode(5);
		TreeNode *l6 = new TreeNode(6);
		TreeNode *l2 = new TreeNode(2, nullptr, l4);
		TreeNode *l3 = new TreeNode(3, l5, l6);
		l1 = new TreeNode(1, l2, l3);

		//   1
		//  / \
		// 2   3
		//  \ / \
		//  4 5  6
		TreeNode *r4 = new TreeNode(4);
		TreeNode *r5 = new TreeNode(5);
		TreeNode *r6 = new TreeNode(6);
		TreeNode *r2 = new TreeNode(2, nullptr, r4);
		TreeNode *r3 = new TreeNode(3, r5, r6);
		r1 = new TreeNode(1, r2, r3);

		REQUIRE(s.isSameTree(l1, r1));
	}

	SECTION("Same structure different values") {
		//   1
		//  / \
		// 2   3
		//  \ / \
		//  4 8  6
		TreeNode *l4 = new TreeNode(4);
		TreeNode *l5 = new TreeNode(8);
		TreeNode *l6 = new TreeNode(6);
		TreeNode *l2 = new TreeNode(2, nullptr, l4);
		TreeNode *l3 = new TreeNode(3, l5, l6);
		l1 = new TreeNode(1, l2, l3);

		//   1
		//  / \
		// 2   3
		//  \ / \
		//  4 5  6
		TreeNode *r4 = new TreeNode(4);
		TreeNode *r5 = new TreeNode(5);
		TreeNode *r6 = new TreeNode(6);
		TreeNode *r2 = new TreeNode(2, nullptr, r4);
		TreeNode *r3 = new TreeNode(3, r5, r6);
		r1 = new TreeNode(1, r2, r3);

		REQUIRE_FALSE(s.isSameTree(l1, r1));
	}

	SECTION("Different structure") {
		//    1
		//   / \
		//  3   2
		// / \   \
		// 5  6   4
		TreeNode *l4 = new TreeNode(4);
		TreeNode *l5 = new TreeNode(5);
		TreeNode *l6 = new TreeNode(6);
		TreeNode *l2 = new TreeNode(2, nullptr, l4);
		TreeNode *l3 = new TreeNode(3, l5, l6);
		l1 = new TreeNode(1, l3, l2);

		//   1
		//  / \
		// 2   3
		//  \ / \
		//  4 5  6
		TreeNode *r4 = new TreeNode(4);
		TreeNode *r5 = new TreeNode(5);
		TreeNode *r6 = new TreeNode(6);
		TreeNode *r2 = new TreeNode(2, nullptr, r4);
		TreeNode *r3 = new TreeNode(3, r5, r6);
		r1 = new TreeNode(1, r2, r3);

		REQUIRE_FALSE(s.isSameTree(l1, r1));
	}


	tree_free(l1);
	tree_free(r1);
}