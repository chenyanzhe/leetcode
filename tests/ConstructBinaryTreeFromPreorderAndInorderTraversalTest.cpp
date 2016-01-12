#include "catch.hpp"

#include "ConstructBinaryTreeFromPreorderAndInorderTraversal.hpp"

#include <string>
using namespace std;

TEST_CASE("Construct Binary Tree from Preorder and Inorder Traversal")
{
  ConstructBinaryTreeFromPreorderAndInorderTraversal s;
  TreeNode* root = nullptr;
  SECTION("Sample test") {
    //   1
    //  / \
    // 2   3
    //  \ / \
    //  4 5  6
    // preorder: 1 2 4 3 5 6
    // inorder:  2 4 1 5 3 6
    vector<int> preorder {1, 2, 4, 3, 5, 6};
    vector<int> inorder {2, 4, 1, 5, 3, 6};
    root = s.buildTree(preorder, inorder);
    string expected = "1 2 # 4 # # 3 5 # # 6 # # ";
    REQUIRE(tree_serialize(root) == expected);
  }
  tree_free(root);
}
