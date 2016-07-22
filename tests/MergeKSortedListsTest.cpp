#include "catch.hpp"

#include "MergeKSortedLists.hpp"

TEST_CASE("Merge K Sorted Lists") {
    MergeKSortedLists s;
    ListNode *result = nullptr;
    SECTION("Normal test") {
        ListNode *h1 = nullptr;
        ListNode *h2 = nullptr;
        ListNode *h3 = nullptr;
        ListNode *n = nullptr;
        n = new ListNode(4);
        n->next = h1;
        h1 = n;
        n = new ListNode(1);
        n->next = h1;
        h1 = n;
        n = new ListNode(5);
        n->next = h2;
        h2 = n;
        n = new ListNode(2);
        n->next = h2;
        h2 = n;
        n = new ListNode(6);
        n->next = h3;
        h3 = n;
        n = new ListNode(3);
        n->next = h3;
        h3 = n;
        vector<ListNode *> lists{h1, h2, h3};
        result = s.mergeKLists(lists);
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
        REQUIRE_FALSE(n == nullptr);
        REQUIRE(n->val == 6);
        n = n->next;
        REQUIRE(n == nullptr);
    }
    SECTION("All empty lists") {
        ListNode *h1 = nullptr;
        ListNode *h2 = nullptr;
        ListNode *h3 = nullptr;
        vector<ListNode *> lists{h1, h2, h3};
        REQUIRE(s.mergeKLists(lists) == nullptr);
    }
    SECTION("Some empty lists") {
        ListNode *h1 = nullptr;
        ListNode *h2 = nullptr;
        ListNode *h3 = nullptr;
        ListNode *n = nullptr;
        n = new ListNode(4);
        n->next = h1;
        h1 = n;
        n = new ListNode(1);
        n->next = h1;
        h1 = n;
        n = new ListNode(5);
        n->next = h2;
        h2 = n;
        n = new ListNode(2);
        n->next = h2;
        h2 = n;
        vector<ListNode *> lists{h1, h2, h3};
        result = s.mergeKLists(lists);
        n = result;
        REQUIRE_FALSE(n == nullptr);
        REQUIRE(n->val == 1);
        n = n->next;
        REQUIRE_FALSE(n == nullptr);
        REQUIRE(n->val == 2);
        n = n->next;
        REQUIRE_FALSE(n == nullptr);
        REQUIRE(n->val == 4);
        n = n->next;
        REQUIRE_FALSE(n == nullptr);
        REQUIRE(n->val == 5);
        n = n->next;
        REQUIRE(n == nullptr);
    }
    list_free(result);
}
