#include "catch.hpp"

#include "SerializeAndDeserializeBinaryTree.hpp"

TEST_CASE("Serialize and Deserialize Binary Tree")
{
  Codec codec;
  TreeNode* root = nullptr;
  TreeNode* new_root = nullptr;
  SECTION("Sample test") {
    TreeNode* _3 = new TreeNode(3);
    TreeNode* _2 = new TreeNode(2, _3, nullptr);
    TreeNode* _1 = new TreeNode(1, nullptr, _2);
    root = _1;
    new_root = codec.deserialize(codec.serialize(root));
    REQUIRE_FALSE(new_root == nullptr);
    REQUIRE(new_root->val == 1);
    REQUIRE(new_root->left == nullptr);
    REQUIRE_FALSE(new_root->right == nullptr);
    REQUIRE(new_root->right->val == 2);
    REQUIRE_FALSE(new_root->right->left == nullptr);
    REQUIRE(new_root->right->left->val == 3);
    REQUIRE(new_root->right->right == nullptr);
  }
  tree_free(root);
  tree_free(new_root);
}
