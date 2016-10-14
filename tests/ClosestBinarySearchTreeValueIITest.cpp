#include "catch.hpp"

#include "ClosestBinarySearchTreeValueII.hpp"

TEST_CASE("Closest Binary Search Tree Value II") {
    ClosestBinarySearchTreeValueII s;
    TreeNode *root = nullptr;
    SECTION("Sample test") {
        /*
         * Create a tree like this:
         *      3
         *     / \
         *    2  4
         *        \
         *        5
         */
        TreeNode *_5 = new TreeNode(5);
        TreeNode *_4 = new TreeNode(4, nullptr, _5);
        TreeNode *_2 = new TreeNode(2);
        TreeNode *_3 = new TreeNode(3, _2, _4);
        root = _3;

        vector<int> expected1 = {2, 3, 4};
        vector<int> result1 = s.closestKValues(root, 1.4, 3);
        sort(result1.begin(), result1.end());
        REQUIRE(result1 == expected1);

        vector<int> expected2 = {2, 3};
        vector<int> result2 = s.closestKValues(root, 2.5, 2);
        sort(result2.begin(), result2.end());
        REQUIRE(result2 == expected2);
    }
    tree_free(root);
}
