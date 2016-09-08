#include "catch.hpp"

#include "InorderSuccessorInBST.hpp"

TEST_CASE("Inorder Successor in BST") {
    InorderSuccessorInBST s;
    TreeNode *l3 = nullptr;
    SECTION("Sample test") {
        //   3
        //  / \
        // 1  4
        //  \
        //   2
        TreeNode *l2 = new TreeNode(2);
        TreeNode *l4 = new TreeNode(4);
        TreeNode *l1 = new TreeNode(1, nullptr, l2);
        l3 = new TreeNode(3, l1, l4);
        REQUIRE(s.inorderSuccessor(l3, l2) == l3);
    }
    tree_free(l3);
}
