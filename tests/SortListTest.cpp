#include "catch.hpp"

#include "SortList.hpp"

TEST_CASE("Sort List") {
    SortList s;
    ListNode *head = nullptr;
    SECTION("Sample test") {
        ListNode *item = nullptr;
        // list (2 -> 1 -> 4 -> 3)
        item = new ListNode(3);
        item->next = head;
        head = item;
        item = new ListNode(4);
        item->next = head;
        head = item;
        item = new ListNode(1);
        item->next = head;
        head = item;
        item = new ListNode(2);
        item->next = head;
        head = item;

        head = s.sortList(head);

        item = head;
        REQUIRE_FALSE(item == nullptr);
        REQUIRE(item->val == 1);
        item = item->next;
        REQUIRE_FALSE(item == nullptr);
        REQUIRE(item->val == 2);
        item = item->next;
        REQUIRE_FALSE(item == nullptr);
        REQUIRE(item->val == 3);
        item = item->next;
        REQUIRE_FALSE(item == nullptr);
        REQUIRE(item->val == 4);
        item = item->next;
        REQUIRE(item == nullptr);
    }
}
