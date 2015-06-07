#include "catch.hpp"

#include "RemoveNthNodeFromEndOfList.hpp"

TEST_CASE("Remove Nth Node From End Of List") {
  RemoveNthNodeFromEndOfList s;

  ListNode *h = nullptr;

  SECTION("Sample test") {
    ListNode *n = nullptr;
    n = new ListNode(5); n->next = h; h = n;
    n = new ListNode(4); n->next = h; h = n;
    n = new ListNode(3); n->next = h; h = n;
    n = new ListNode(2); n->next = h; h = n;
    n = new ListNode(1); n->next = h; h = n;

    ListNode *result = s.removeNthFromEnd(h, 2);

    REQUIRE_FALSE(result == nullptr); REQUIRE(result->val == 1); result = result->next;
    REQUIRE_FALSE(result == nullptr); REQUIRE(result->val == 2); result = result->next;
    REQUIRE_FALSE(result == nullptr); REQUIRE(result->val == 3); result = result->next;
    REQUIRE_FALSE(result == nullptr); REQUIRE(result->val == 5); result = result->next;
    REQUIRE(result == nullptr);
  }

  SECTION("Empty list") {
    REQUIRE(s.removeNthFromEnd(nullptr, 0) == nullptr);
  }

  SECTION("Single element list") {
    h = new ListNode(1);
    REQUIRE(s.removeNthFromEnd(h, 1) == nullptr);
  }

  SECTION("Remove head of the list") {
    ListNode *n = nullptr;
    n = new ListNode(5); n->next = h; h = n;
    n = new ListNode(4); n->next = h; h = n;
    n = new ListNode(3); n->next = h; h = n;
    n = new ListNode(2); n->next = h; h = n;
    n = new ListNode(1); n->next = h; h = n;

    ListNode *result = s.removeNthFromEnd(h, 5);

    REQUIRE_FALSE(result == nullptr); REQUIRE(result->val == 2); result = result->next;
    REQUIRE_FALSE(result == nullptr); REQUIRE(result->val == 3); result = result->next;
    REQUIRE_FALSE(result == nullptr); REQUIRE(result->val == 4); result = result->next;
    REQUIRE_FALSE(result == nullptr); REQUIRE(result->val == 5); result = result->next;
    REQUIRE(result == nullptr);
  }

  while (h != nullptr) {
    ListNode *n = h;
    h = h->next;
    delete n;
  }
}
