#include "catch.hpp"

#include "DeleteNodeInALinkedList.hpp"

TEST_CASE("Delete Node in a Linked List")
{
  DeleteNodeInALinkedList s;
  ListNode* head = nullptr;
  SECTION("Sample test") {
    ListNode* _4 = new ListNode(4);
    _4->next = head;
    head = _4;
    ListNode* _3 = new ListNode(3);
    _3->next = head;
    head = _3;
    ListNode* _2 = new ListNode(2);
    _2->next = head;
    head = _2;
    ListNode* _1 = new ListNode(1);
    _1->next = head;
    head = _1;
    s.deleteNode(_3);
    ListNode* n = head;
    REQUIRE_FALSE(n == nullptr);
    REQUIRE(n->val == 1);
    n = n->next;
    REQUIRE_FALSE(n == nullptr);
    REQUIRE(n->val == 2);
    n = n->next;
    REQUIRE_FALSE(n == nullptr);
    REQUIRE(n->val == 4);
    n = n->next;
    REQUIRE(n == nullptr);
  }
}
