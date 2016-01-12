#include "catch.hpp"

#include "ReverseLinkedListII.hpp"

TEST_CASE("Reverse Linked List II")
{
  ReverseLinkedListII s;
  ListNode* l = nullptr;
  SECTION("Sample test") {
    ListNode* item = nullptr;
    // (1 -> 2 -> 3 -> 4 -> 5)
    item = new ListNode(5);
    item->next = l;
    l = item;
    item = new ListNode(4);
    item->next = l;
    l = item;
    item = new ListNode(3);
    item->next = l;
    l = item;
    item = new ListNode(2);
    item->next = l;
    l = item;
    item = new ListNode(1);
    item->next = l;
    l = item;
    l = s.reverseBetween(l, 2, 4);
    // should be (1 -> 4 -> 3 -> 2 -> 5)
    item = l;
    REQUIRE_FALSE(item == nullptr);
    REQUIRE(item->val == 1);
    item = item->next;
    REQUIRE_FALSE(item == nullptr);
    REQUIRE(item->val == 4);
    item = item->next;
    REQUIRE_FALSE(item == nullptr);
    REQUIRE(item->val == 3);
    item = item->next;
    REQUIRE_FALSE(item == nullptr);
    REQUIRE(item->val == 2);
    item = item->next;
    REQUIRE_FALSE(item == nullptr);
    REQUIRE(item->val == 5);
    item = item->next;
    REQUIRE(item == nullptr);
  }
  SECTION("Corner case 1") {
    ListNode* item = nullptr;
    // (1)
    item = new ListNode(1);
    item->next = l;
    l = item;
    l = s.reverseBetween(l, 1, 1);
    // should be (1)
    item = l;
    REQUIRE_FALSE(item == nullptr);
    REQUIRE(item->val == 1);
    item = item->next;
    REQUIRE(item == nullptr);
  }
  SECTION("Corner case 2") {
    ListNode* item = nullptr;
    // (1 -> 2 -> 3 -> 4 -> 5)
    item = new ListNode(5);
    item->next = l;
    l = item;
    item = new ListNode(4);
    item->next = l;
    l = item;
    item = new ListNode(3);
    item->next = l;
    l = item;
    item = new ListNode(2);
    item->next = l;
    l = item;
    item = new ListNode(1);
    item->next = l;
    l = item;
    l = s.reverseBetween(l, 1, 5);
    // should be (5 -> 4 -> 3 -> 2 -> 1)
    item = l;
    REQUIRE_FALSE(item == nullptr);
    REQUIRE(item->val == 5);
    item = item->next;
    REQUIRE_FALSE(item == nullptr);
    REQUIRE(item->val == 4);
    item = item->next;
    REQUIRE_FALSE(item == nullptr);
    REQUIRE(item->val == 3);
    item = item->next;
    REQUIRE_FALSE(item == nullptr);
    REQUIRE(item->val == 2);
    item = item->next;
    REQUIRE_FALSE(item == nullptr);
    REQUIRE(item->val == 1);
    item = item->next;
    REQUIRE(item == nullptr);
  }
  list_free(l);
}
