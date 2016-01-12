#include "catch.hpp"

#include "PlusOne.hpp"

TEST_CASE("Plus One")
{
  PlusOne s;
  SECTION("Sample tests") {
    vector<int> num1 {1};
    vector<int> res1 {2};
    REQUIRE(s.plusOne(num1) == res1);
    vector<int> num2 {9};
    vector<int> res2 {1, 0};
    REQUIRE(s.plusOne(num2) == res2);
    vector<int> num3 {9, 9, 9};
    vector<int> res3 {1, 0, 0, 0};
    REQUIRE(s.plusOne(num3) == res3);
    vector<int> num4 {4, 6, 8};
    vector<int> res4 {4, 6, 9};
    REQUIRE(s.plusOne(num4) == res4);
  }
}
