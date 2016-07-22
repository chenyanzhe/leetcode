#include "catch.hpp"

#include "ConstructBinaryTreeFromInorderAndPostorderTraversal.hpp"

using namespace std;

TEST_CASE("Construct Binary Tree from Inorder and Postorder Traversal") {
    ConstructBinaryTreeFromInorderAndPostorderTraversal s;
    TreeNode *root = nullptr;
    SECTION("Sample test") {
        //   1
        //  / \
    // 2   3
        //  \ / \
    //  4 5  6
        // inorder: 2 4 1 5 3 6
        // postorder: 4 2 5 6 3 1
        vector<int> inorder{2, 4, 1, 5, 3, 6};
        vector<int> postorder{4, 2, 5, 6, 3, 1};
        root = s.buildTree(inorder, postorder);
        string expected = "1 2 # 4 # # 3 5 # # 6 # # ";
        REQUIRE(tree_serialize(root) == expected);
    }
    tree_free(root);
}
