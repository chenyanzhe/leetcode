#include "catch.hpp"

#include "AddTwoNumbers.hpp"

TEST_CASE("Add Two Numbers") {
    AddTwoNumbers s;
    ListNode *l1 = nullptr;
    ListNode *l2 = nullptr;
    ListNode *l3 = nullptr;
    SECTION("Sample test") {
        ListNode *item = nullptr;
        // l1 (2 -> 4 -> 3)
        item = new ListNode(3);
        item->next = l1;
        l1 = item;
        item = new ListNode(4);
        item->next = l1;
        l1 = item;
        item = new ListNode(2);
        item->next = l1;
        l1 = item;
        // l2 (5 -> 6 -> 4)
        item = new ListNode(4);
        item->next = l2;
        l2 = item;
        item = new ListNode(6);
        item->next = l2;
        l2 = item;
        item = new ListNode(5);
        item->next = l2;
        l2 = item;
        l3 = s.addTwoNumbers(l1, l2);
        // should be (7 -> 0 -> 8)
        item = l3;
        REQUIRE_FALSE(item == nullptr);
        REQUIRE(item->val == 7);
        item = item->next;
        REQUIRE_FALSE(item == nullptr);
        REQUIRE(item->val == 0);
        item = item->next;
        REQUIRE_FALSE(item == nullptr);
        REQUIRE(item->val == 8);
        item = item->next;
        REQUIRE(item == nullptr);
    }
    SECTION("Both l1 and l2 are empty lists") {
        l3 = s.addTwoNumbers(l1, l2);
        REQUIRE(l3 == nullptr);
    }
    SECTION("l1 is an empty list") {
        ListNode *item = nullptr;
        // l2 (5 -> 6 -> 4)
        item = new ListNode(4);
        item->next = l2;
        l2 = item;
        item = new ListNode(6);
        item->next = l2;
        l2 = item;
        item = new ListNode(5);
        item->next = l2;
        l2 = item;
        l3 = s.addTwoNumbers(l1, l2);
        item = l3;
        REQUIRE_FALSE(item == nullptr);
        REQUIRE(item->val == 5);
        item = item->next;
        REQUIRE_FALSE(item == nullptr);
        REQUIRE(item->val == 6);
        item = item->next;
        REQUIRE_FALSE(item == nullptr);
        REQUIRE(item->val == 4);
        item = item->next;
        REQUIRE(item == nullptr);
    }
    SECTION("l2 is an empty list") {
        ListNode *item = nullptr;
        // l1 (2 -> 4 -> 3)
        item = new ListNode(3);
        item->next = l1;
        l1 = item;
        item = new ListNode(4);
        item->next = l1;
        l1 = item;
        item = new ListNode(2);
        item->next = l1;
        l1 = item;
        l3 = s.addTwoNumbers(l1, l2);
        item = l3;
        REQUIRE_FALSE(item == nullptr);
        REQUIRE(item->val == 2);
        item = item->next;
        REQUIRE_FALSE(item == nullptr);
        REQUIRE(item->val == 4);
        item = item->next;
        REQUIRE_FALSE(item == nullptr);
        REQUIRE(item->val == 3);
        item = item->next;
        REQUIRE(item == nullptr);
    }
    SECTION("Carry to be the highest bit") {
        ListNode *item = nullptr;
        // l1 (2 -> 4 -> 3)
        item = new ListNode(3);
        item->next = l1;
        l1 = item;
        item = new ListNode(4);
        item->next = l1;
        l1 = item;
        item = new ListNode(2);
        item->next = l1;
        l1 = item;
        // l2 (5 -> 6 -> 6)
        item = new ListNode(6);
        item->next = l2;
        l2 = item;
        item = new ListNode(6);
        item->next = l2;
        l2 = item;
        item = new ListNode(5);
        item->next = l2;
        l2 = item;
        l3 = s.addTwoNumbers(l1, l2);
        // should be (7 -> 0 -> 0 -> 1)
        item = l3;
        REQUIRE_FALSE(item == nullptr);
        REQUIRE(item->val == 7);
        item = item->next;
        REQUIRE_FALSE(item == nullptr);
        REQUIRE(item->val == 0);
        item = item->next;
        REQUIRE_FALSE(item == nullptr);
        REQUIRE(item->val == 0);
        item = item->next;
        REQUIRE_FALSE(item == nullptr);
        REQUIRE(item->val == 1);
        item = item->next;
        REQUIRE(item == nullptr);
    }
    // deallocate all lists
    list_free(l1);
    list_free(l2);
    list_free(l3);
}
