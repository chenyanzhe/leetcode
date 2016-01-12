#include "catch.hpp"

#include "Anagrams.hpp"

TEST_CASE("Anagrams")
{
  Anagrams s;
  SECTION("Normal test") {
    vector<string> nums {"eat", "sea", "tea", "dormitory", "fee", "dirtyroom"};
    vector<string> expected {"eat", "tea", "dormitory", "dirtyroom"};
    vector<string> result = s.anagrams(nums);
    REQUIRE(result.size() == 4);

    for (int i = 0; i < 4; i++) {
      REQUIRE_FALSE(find(expected.begin(), expected.end(),
                         result[i]) == expected.end());
    }
  }
}
