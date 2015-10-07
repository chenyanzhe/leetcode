#include "catch.hpp"

#include "MergeTwoSortedLists.hpp"

TEST_CASE("Merge Two Sorted Lists") {
  MergeTwoSortedLists s;

  ListNode* h = nullptr;
  ListNode* h1 = nullptr;
  ListNode* h2 = nullptr;

  SECTION("Normal tests") {
    ListNode *i1 = nullptr;
    i1 = new ListNode(5); i1->next = h1; h1 = i1;
    i1 = new ListNode(3); i1->next = h1; h1 = i1;
    i1 = new ListNode(1); i1->next = h1; h1 = i1;

    ListNode *i2 = nullptr;
    i2 = new ListNode(6); i2->next = h2; h2 = i2;
    i2 = new ListNode(4); i2->next = h2; h2 = i2;
    i2 = new ListNode(2); i2->next = h2; h2 = i2;

    h = s.mergeTwoLists(h1, h2);

    ListNode *i = h;
    REQUIRE_FALSE(i == nullptr); REQUIRE(i->val == 1); i = i->next;
    REQUIRE_FALSE(i == nullptr); REQUIRE(i->val == 2); i = i->next;
    REQUIRE_FALSE(i == nullptr); REQUIRE(i->val == 3); i = i->next;
    REQUIRE_FALSE(i == nullptr); REQUIRE(i->val == 4); i = i->next;
    REQUIRE_FALSE(i == nullptr); REQUIRE(i->val == 5); i = i->next;
    REQUIRE_FALSE(i == nullptr); REQUIRE(i->val == 6); i = i->next;
    REQUIRE(i == nullptr);
  }

  SECTION("One empty list") {
    ListNode *i1 = nullptr;
    i1 = new ListNode(5); i1->next = h1; h1 = i1;
    i1 = new ListNode(3); i1->next = h1; h1 = i1;
    i1 = new ListNode(1); i1->next = h1; h1 = i1;

    h = s.mergeTwoLists(h1, h2);

    ListNode *i = h;
    REQUIRE_FALSE(i == nullptr); REQUIRE(i->val == 1); i = i->next;
    REQUIRE_FALSE(i == nullptr); REQUIRE(i->val == 3); i = i->next;
    REQUIRE_FALSE(i == nullptr); REQUIRE(i->val == 5); i = i->next;
    REQUIRE(i == nullptr);
  }

  SECTION("Two empty lists") {
    h = s.mergeTwoLists(h1, h2);
    REQUIRE(h == nullptr);
  }

  SECTION("Two identical lists") {
    ListNode *i1 = nullptr;
    i1 = new ListNode(5); i1->next = h1; h1 = i1;
    i1 = new ListNode(3); i1->next = h1; h1 = i1;
    i1 = new ListNode(1); i1->next = h1; h1 = i1;

    ListNode *i2 = nullptr;
    i2 = new ListNode(5); i2->next = h2; h2 = i2;
    i2 = new ListNode(3); i2->next = h2; h2 = i2;
    i2 = new ListNode(1); i2->next = h2; h2 = i2;

    h = s.mergeTwoLists(h1, h2);

    ListNode *i = h;
    REQUIRE_FALSE(i == nullptr); REQUIRE(i->val == 1); i = i->next;
    REQUIRE_FALSE(i == nullptr); REQUIRE(i->val == 1); i = i->next;
    REQUIRE_FALSE(i == nullptr); REQUIRE(i->val == 3); i = i->next;
    REQUIRE_FALSE(i == nullptr); REQUIRE(i->val == 3); i = i->next;
    REQUIRE_FALSE(i == nullptr); REQUIRE(i->val == 5); i = i->next;
    REQUIRE_FALSE(i == nullptr); REQUIRE(i->val == 5); i = i->next;
    REQUIRE(i == nullptr);
  }

  list_free(h);
}
