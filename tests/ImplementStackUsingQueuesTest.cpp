#include "catch.hpp"

#include "ImplementStackUsingQueues.hpp"

TEST_CASE("Implement Stack using Queues")
{
  ImplementStackUsingQueues s;
  SECTION("Sample test") {
    s.push(3);
    REQUIRE(s.top() == 3);
    s.push(2);
    REQUIRE(s.top() == 2);
    s.push(1);
    REQUIRE(s.top() == 1);
    s.pop();
    REQUIRE(s.top() == 2);
    s.pop();
    REQUIRE(s.top() == 3);
    s.pop();
    s.pop();
    s.top();
    s.top();
  }
}
