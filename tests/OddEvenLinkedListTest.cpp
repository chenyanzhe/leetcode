#include "catch.hpp"

#include "OddEvenLinkedList.hpp"

TEST_CASE("Odd Even Linked List") {
    OddEvenLinkedList s;
    ListNode *head = nullptr;
    SECTION("Sample test") {
        ListNode *item = nullptr;
        // list (1 -> 2 -> 3 -> 4 -> 5)
        item = new ListNode(5);
        item->next = head;
        head = item;
        item = new ListNode(4);
        item->next = head;
        head = item;
        item = new ListNode(3);
        item->next = head;
        head = item;
        item = new ListNode(2);
        item->next = head;
        head = item;
        item = new ListNode(1);
        item->next = head;
        head = item;

        head = s.oddEvenList(head);

        // list (1 -> 3 -> 5 -> 2 -> 4)
        item = head;
        REQUIRE_FALSE(item == nullptr);
        REQUIRE(item->val == 1);
        item = item->next;
        REQUIRE_FALSE(item == nullptr);
        REQUIRE(item->val == 3);
        item = item->next;
        REQUIRE_FALSE(item == nullptr);
        REQUIRE(item->val == 5);
        item = item->next;
        REQUIRE_FALSE(item == nullptr);
        REQUIRE(item->val == 2);
        item = item->next;
        REQUIRE_FALSE(item == nullptr);
        REQUIRE(item->val == 4);
        item = item->next;
        REQUIRE(item == nullptr);
    }
}
