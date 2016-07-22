#include "catch.hpp"

#include "UniqueBinarySearchTreesII.hpp"

using namespace std;

TEST_CASE("Unique Binary Search Trees II") {
    UniqueBinarySearchTreesII s;
    vector<TreeNode *> result;
    SECTION("Sample test") {
        vector<string> expected{
                "1 # 3 2 # # # ",
                "3 2 1 # # # # ",
                "3 1 # 2 # # # ",
                "2 1 # # 3 # # ",
                "1 # 2 # 3 # # "
        };
        result = s.generateTrees(3);
        REQUIRE(result.size() == expected.size());

        for (auto t : result) {
            REQUIRE_FALSE(find(expected.begin(), expected.end(),
                               tree_serialize(t)) == expected.end());
        }
    }
}
