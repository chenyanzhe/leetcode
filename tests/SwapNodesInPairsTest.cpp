#include "catch.hpp"

#include "SwapNodesInPairs.hpp"

TEST_CASE("Swap Nodes In Pairs") {
    SwapNodesInPairs s;
    ListNode *head = nullptr;
    ListNode *result = nullptr;
    SECTION("Sample test") {
        ListNode *n = nullptr;
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
        result = s.swapPairs(head);
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
        REQUIRE(n == nullptr);
    }
    SECTION("Empty list") {
        REQUIRE(s.swapPairs(head) == nullptr);
    }
    SECTION("Odd items in list") {
        ListNode *n = nullptr;
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
        result = s.swapPairs(head);
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
    SECTION("Single item in list") {
        ListNode *n = nullptr;
        n = new ListNode(1);
        n->next = head;
        head = n;
        result = s.swapPairs(head);
        n = result;
        REQUIRE_FALSE(n == nullptr);
        REQUIRE(n->val == 1);
        n = n->next;
        REQUIRE(n == nullptr);
    }
    SECTION("Two items in list") {
        ListNode *n = nullptr;
        n = new ListNode(5);
        n->next = head;
        head = n;
        n = new ListNode(4);
        n->next = head;
        head = n;
        result = s.swapPairs(head);
        n = result;
        REQUIRE_FALSE(n == nullptr);
        REQUIRE(n->val == 5);
        n = n->next;
        REQUIRE_FALSE(n == nullptr);
        REQUIRE(n->val == 4);
        n = n->next;
        REQUIRE(n == nullptr);
    }
    list_free(result);
}
