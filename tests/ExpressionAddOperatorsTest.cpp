#include "catch.hpp"

#include "ExpressionAddOperators.hpp"

TEST_CASE("Expression Add Operators") {
  ExpressionAddOperators s;

  SECTION("Sample tests") {
    vector<string> expected1 { "1+2+3", "1*2*3" };
    vector<string> result1 = s.addOperators("123", 6);

    REQUIRE(result1.size() == expected1.size());
    for (int i = 0; i < result1.size(); i++) 
      REQUIRE_FALSE(find(expected1.begin(), expected1.end(), result1[i]) == expected1.end());

    vector<string> expected2 { "2*3+2", "2+3*2" };
    vector<string> result2 = s.addOperators("232", 8);
    
    REQUIRE(result2.size() == expected2.size());
    for (int i = 0; i < result2.size(); i++) 
      REQUIRE_FALSE(find(expected2.begin(), expected2.end(), result2[i]) == expected2.end());

    vector<string> expected3 { "1*0+5", "10-5" };
    vector<string> result3 = s.addOperators("105", 5);
    
    REQUIRE(result3.size() == expected3.size());
    for (int i = 0; i < result3.size(); i++) 
      REQUIRE_FALSE(find(expected3.begin(), expected3.end(), result3[i]) == expected3.end());

    vector<string> expected4 { "0+0", "0-0", "0*0" };
    vector<string> result4 = s.addOperators("00", 0);

    REQUIRE(result4.size() == expected4.size());
    for (int i = 0; i < result4.size(); i++) 
      REQUIRE_FALSE(find(expected4.begin(), expected4.end(), result4[i]) == expected4.end());

    vector<string> expected5 {};
    vector<string> result5 = s.addOperators("3456237490", 9191);
    REQUIRE(result5.size() == expected5.size());
  }
}
