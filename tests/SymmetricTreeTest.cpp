#include "catch.hpp"

#include "SymmetricTree.hpp"

TEST_CASE("Symmetric Tree") {
  	SymmetricTree s;

  	TreeNode *l = nullptr;

	SECTION("Sample test") {
		//     1
		//    / \
		//   2   2
		//  / \ / \
		// 3  4 4  3
		TreeNode *l3_1 = new TreeNode(3);
		TreeNode *l4_1 = new TreeNode(4);
		TreeNode *l4_2 = new TreeNode(4);
		TreeNode *l3_2 = new TreeNode(3);
		TreeNode *l2_1 = new TreeNode(2, l3_1, l4_1);
		TreeNode *l2_2 = new TreeNode(2, l4_2, l3_2);
		l = new TreeNode(1, l2_1, l2_2);

		REQUIRE(s.isSymmetric(l));
	}

	tree_free(l);
}
