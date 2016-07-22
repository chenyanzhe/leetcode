#include "catch.hpp"

#include "RemoveLinkedListElements.hpp"

TEST_CASE("Remove Linked List Elements") {
    RemoveLinkedListElements s;
    ListNode *l = nullptr;
    SECTION("Sample test") {
        ListNode *_6 = new ListNode(6);
        _6->next = l;
        l = _6;
        ListNode *_5 = new ListNode(5);
        _5->next = l;
        l = _5;
        ListNode *_4 = new ListNode(4);
        _4->next = l;
        l = _4;
        ListNode *_3 = new ListNode(3);
        _3->next = l;
        l = _3;
        ListNode *_6_2 = new ListNode(6);
        _6_2->next = l;
        l = _6_2;
        ListNode *_2 = new ListNode(2);
        _2->next = l;
        l = _2;
        ListNode *_1 = new ListNode(1);
        _1->next = l;
        l = _1;
        s.removeElements(l, 6);
        ListNode *n = l;
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
