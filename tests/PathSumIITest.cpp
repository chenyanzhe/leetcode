#include "catch.hpp"

#include "PathSumII.hpp"

using namespace std;

TEST_CASE("Path Sum II") {
    PathSumII s;
    TreeNode *root = nullptr;
    SECTION("Sample test") {
        /*
           *         5
           *       /   \
           *      4     8
           *     /     / \
           *    11    13  4
           *   /  \      / \
           *  7    2    5   1
           */
        TreeNode *_7 = new TreeNode(7);
        TreeNode *_2 = new TreeNode(2);
        TreeNode *_5 = new TreeNode(5);
        TreeNode *_1 = new TreeNode(1);
        TreeNode *_11 = new TreeNode(11, _7, _2);
        TreeNode *_13 = new TreeNode(13);
        TreeNode *_4 = new TreeNode(4, _5, _1);
        TreeNode *_4_2 = new TreeNode(4, _11, nullptr);
        TreeNode *_8 = new TreeNode(8, _13, _4);
        TreeNode *_5_2 = new TreeNode(5, _4_2, _8);
        root = _5_2;
        vector<vector<int>> result = s.pathSum(root, 22);
        // There exist two root-to-leaf paths which sum is 22, which are 5->4->11->2 and 5->8->4->5.
        vector<vector<int>> expected{
                {5, 4, 11, 2},
                {5, 8, 4,  5}
        };
        REQUIRE(result.size() == expected.size());

        for (int i = 0; i < result.size(); i++) {
            REQUIRE_FALSE(find(expected.begin(), expected.end(),
                               result[i]) == expected.end());
        }
    }
    tree_free(root);
}
