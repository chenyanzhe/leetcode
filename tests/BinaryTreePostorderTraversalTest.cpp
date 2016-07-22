#include "catch.hpp"

#include "BinaryTreePostorderTraversal.hpp"

TEST_CASE("Binary Tree Postorder Traversal") {
    BinaryTreePostorderTraversal s;
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
        vector<int> expected{9, 15, 7, 20, 3};
        REQUIRE(s.postorderTraversal(root) == expected);
    }
    tree_free(root);
}

