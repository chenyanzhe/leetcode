#include "catch.hpp"

#include "RemoveDuplicatesFromSortedListII.hpp"

TEST_CASE("Remove Duplicates from Sorted List II") {
    RemoveDuplicatesFromSortedListII s;
    ListNode *l = nullptr;
    SECTION("Sample test 1") {
        ListNode *item = nullptr;
        // 1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5
        item = new ListNode(5);
        item->next = l;
        l = item;
        item = new ListNode(4);
        item->next = l;
        l = item;
        item = new ListNode(4);
        item->next = l;
        l = item;
        item = new ListNode(3);
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
        l = s.deleteDuplicates(l);
        // should be 1 -> 2 -> 5
        item = l;
        REQUIRE_FALSE(item == nullptr);
        REQUIRE(item->val == 1);
        item = item->next;
        REQUIRE_FALSE(item == nullptr);
        REQUIRE(item->val == 2);
        item = item->next;
        REQUIRE_FALSE(item == nullptr);
        REQUIRE(item->val == 5);
        item = item->next;
        REQUIRE(item == nullptr);
    }
    SECTION("Sample test 2") {
        ListNode *item = nullptr;
        // 1 -> 1 -> 1 -> 2 -> 3
        item = new ListNode(3);
        item->next = l;
        l = item;
        item = new ListNode(2);
        item->next = l;
        l = item;
        item = new ListNode(1);
        item->next = l;
        l = item;
        item = new ListNode(1);
        item->next = l;
        l = item;
        item = new ListNode(1);
        item->next = l;
        l = item;
        l = s.deleteDuplicates(l);
        // should be 2 -> 3
        item = l;
        REQUIRE_FALSE(item == nullptr);
        REQUIRE(item->val == 2);
        item = item->next;
        REQUIRE_FALSE(item == nullptr);
        REQUIRE(item->val == 3);
        item = item->next;
        REQUIRE(item == nullptr);
    }
    SECTION("All duplicates") {
        ListNode *item = nullptr;
        // 1 -> 1 -> 1 -> 2 -> 2
        item = new ListNode(2);
        item->next = l;
        l = item;
        item = new ListNode(2);
        item->next = l;
        l = item;
        item = new ListNode(1);
        item->next = l;
        l = item;
        item = new ListNode(1);
        item->next = l;
        l = item;
        item = new ListNode(1);
        item->next = l;
        l = item;
        l = s.deleteDuplicates(l);
        // should be empty list
        item = l;
        REQUIRE(item == nullptr);
    }
    list_free(l);
}
