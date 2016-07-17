#include "catch.hpp"

#include "HouseRobberIII.hpp"

TEST_CASE("House Robber III")
{
  HouseRobberIII s;
  TreeNode* root = nullptr;
  SECTION("Sample test I") {
    /*
     *   3
     *  / \
     * 2   3
     *  \   \
     *   3   1
     */
    TreeNode* _l3_3 = new TreeNode(3);
    TreeNode* _l3_1 = new TreeNode(1);
    TreeNode* _l2_2 = new TreeNode(2, nullptr, _l3_3);
    TreeNode* _l2_3 = new TreeNode(3, nullptr, _l3_1);
    TreeNode* _l1_3 = new TreeNode(3, _l2_2, _l2_3);
    root = _l1_3;
    REQUIRE(s.rob(root) == 7);
  }
  SECTION("Sample test II") {
    /*
     *     3
     *    / \
     *   4   5
     *  / \   \
     * 1   3   1
     */
    TreeNode* _l3_1_a = new TreeNode(1);
    TreeNode* _l3_3 = new TreeNode(3);
    TreeNode* _l3_1_b = new TreeNode(1);
    TreeNode* _l2_4 = new TreeNode(4, _l3_1_a, _l3_3);
    TreeNode* _l2_5 = new TreeNode(5, nullptr, _l3_1_b);
    TreeNode* _l1_3 = new TreeNode(3, _l2_4, _l2_5);
    root = _l1_3;
    REQUIRE(s.rob(root) == 9);
  }
  tree_free(root);
}
