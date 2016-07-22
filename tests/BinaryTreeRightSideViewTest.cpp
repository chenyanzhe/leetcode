#include "catch.hpp"

#include "BinaryTreeRightSideView.hpp"

TEST_CASE("Binary Tree Right Side View") {
    BinaryTreeRightSideView s;
    TreeNode *root = nullptr;
    SECTION("Sample test") {
        TreeNode *_5 = new TreeNode(5);
        TreeNode *_4 = new TreeNode(4);
        TreeNode *_2 = new TreeNode(2, nullptr, _5);
        TreeNode *_3 = new TreeNode(3, nullptr, _4);
        TreeNode *_1 = new TreeNode(1, _2, _3);
        root = _1;
        vector<int> expected{1, 3, 4};
        vector<int> result = s.rightSideView(root);
        REQUIRE(result == expected);
    }
    tree_free(root);
}
