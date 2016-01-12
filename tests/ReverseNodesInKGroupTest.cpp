#include "catch.hpp"

#include "ReverseNodesInKGroup.hpp"

TEST_CASE("Reverse Nodes In K Group")
{
  ReverseNodesInKGroup s;
  ListNode* head = nullptr;
  ListNode* result = nullptr;
  SECTION("Sample tests") {
    ListNode* n;
    n = new ListNode(5);
    n->next = head;
    head = n;
    n = new ListNode(4);
    n->next = head;
    head = n;
    n = new ListNode(3);
    n->next = head;
    head = n;
    n = new ListNode(2);
    n->next = head;
    head = n;
    n = new ListNode(1);
    n->next = head;
    head = n;
    SECTION("k = 5") {
      result = s.reverseKGroup(head, 5);
      n = result;
      REQUIRE_FALSE(n == nullptr);
      REQUIRE(n->val == 5);
      n = n->next;
      REQUIRE_FALSE(n == nullptr);
      REQUIRE(n->val == 4);
      n = n->next;
      REQUIRE_FALSE(n == nullptr);
      REQUIRE(n->val == 3);
      n = n->next;
      REQUIRE_FALSE(n == nullptr);
      REQUIRE(n->val == 2);
      n = n->next;
      REQUIRE_FALSE(n == nullptr);
      REQUIRE(n->val == 1);
      n = n->next;
      REQUIRE(n == nullptr);
    }
    SECTION("k = 4") {
      result = s.reverseKGroup(head, 4);
      n = result;
      REQUIRE_FALSE(n == nullptr);
      REQUIRE(n->val == 4);
      n = n->next;
      REQUIRE_FALSE(n == nullptr);
      REQUIRE(n->val == 3);
      n = n->next;
      REQUIRE_FALSE(n == nullptr);
      REQUIRE(n->val == 2);
      n = n->next;
      REQUIRE_FALSE(n == nullptr);
      REQUIRE(n->val == 1);
      n = n->next;
      REQUIRE_FALSE(n == nullptr);
      REQUIRE(n->val == 5);
      n = n->next;
      REQUIRE(n == nullptr);
    }
    SECTION("k = 3") {
      result = s.reverseKGroup(head, 3);
      n = result;
      REQUIRE_FALSE(n == nullptr);
      REQUIRE(n->val == 3);
      n = n->next;
      REQUIRE_FALSE(n == nullptr);
      REQUIRE(n->val == 2);
      n = n->next;
      REQUIRE_FALSE(n == nullptr);
      REQUIRE(n->val == 1);
      n = n->next;
      REQUIRE_FALSE(n == nullptr);
      REQUIRE(n->val == 4);
      n = n->next;
      REQUIRE_FALSE(n == nullptr);
      REQUIRE(n->val == 5);
      n = n->next;
      REQUIRE(n == nullptr);
    }
    SECTION("k = 2") {
      result = s.reverseKGroup(head, 2);
      n = result;
      REQUIRE_FALSE(n == nullptr);
      REQUIRE(n->val == 2);
      n = n->next;
      REQUIRE_FALSE(n == nullptr);
      REQUIRE(n->val == 1);
      n = n->next;
      REQUIRE_FALSE(n == nullptr);
      REQUIRE(n->val == 4);
      n = n->next;
      REQUIRE_FALSE(n == nullptr);
      REQUIRE(n->val == 3);
      n = n->next;
      REQUIRE_FALSE(n == nullptr);
      REQUIRE(n->val == 5);
      n = n->next;
      REQUIRE(n == nullptr);
    }
    SECTION("k = 1") {
      result = s.reverseKGroup(head, 1);
      n = result;
      REQUIRE_FALSE(n == nullptr);
      REQUIRE(n->val == 1);
      n = n->next;
      REQUIRE_FALSE(n == nullptr);
      REQUIRE(n->val == 2);
      n = n->next;
      REQUIRE_FALSE(n == nullptr);
      REQUIRE(n->val == 3);
      n = n->next;
      REQUIRE_FALSE(n == nullptr);
      REQUIRE(n->val == 4);
      n = n->next;
      REQUIRE_FALSE(n == nullptr);
      REQUIRE(n->val == 5);
      n = n->next;
      REQUIRE(n == nullptr);
    }
    SECTION("k is larger than number of elements in list") {
      result = s.reverseKGroup(head, 6);
      n = result;
      REQUIRE_FALSE(n == nullptr);
      REQUIRE(n->val == 1);
      n = n->next;
      REQUIRE_FALSE(n == nullptr);
      REQUIRE(n->val == 2);
      n = n->next;
      REQUIRE_FALSE(n == nullptr);
      REQUIRE(n->val == 3);
      n = n->next;
      REQUIRE_FALSE(n == nullptr);
      REQUIRE(n->val == 4);
      n = n->next;
      REQUIRE_FALSE(n == nullptr);
      REQUIRE(n->val == 5);
      n = n->next;
      REQUIRE(n == nullptr);
    }
  }
  SECTION("Emtpy list") {
    REQUIRE(s.reverseKGroup(head, 0) == nullptr);
  }
  list_free(result);
}
