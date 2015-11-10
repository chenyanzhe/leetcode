#include "catch.hpp"

#include "IntersectionOfTwoLinkedLists.hpp"

TEST_CASE("Intersection of Two Linked Lists") {
    IntersectionOfTwoLinkedLists s;

    ListNode *h1 = nullptr;
    ListNode *h2 = nullptr;

    SECTION("Sample test") {
        ListNode *n = nullptr;
        ListNode *expected = nullptr;

        n = new ListNode(5); n->next = h1; h1 = n;
        n = new ListNode(4); n->next = h1; h1 = n;
        n = new ListNode(3); n->next = h1; h1 = n; expected = n;
        n = new ListNode(2); n->next = h1; h1 = n;
        n = new ListNode(1); n->next = h1; h1 = n;

        h2 = expected;
        n = new ListNode(3); n->next = h2; h2 = n;
        n = new ListNode(2); n->next = h2; h2 = n;
        n = new ListNode(1); n->next = h2; h2 = n;

        REQUIRE(s.getIntersectionNode(h1, h2) == expected);
    }

    //FIXME: how to correctly free two intersected lists
}
