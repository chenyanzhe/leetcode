#include "catch.hpp"

#include "VerifyPreorderSequenceInBinarySearchTree.hpp"

TEST_CASE("Verify Preorder Sequence in Binary Search Tree") {
    VerifyPreorderSequenceInBinarySearchTree s;
    SECTION("Sample test") {
        /*
         * Traverse a tree like this:
         *      3
         *     / \
         *    2  4
         *        \
         *        5
         */
        vector<int> preorder{3, 2, 4, 5};
        REQUIRE(s.verifyPreorder(preorder));
    }
}
