#include "catch.hpp"

#include "PalindromeLinkedList.hpp"

TEST_CASE("Palindrome Linked List") {
    PalindromeLinkedList s;
    ListNode *head = nullptr;
    SECTION("Sample test") {
        ListNode *_1 = new ListNode(1);
        _1->next = head;
        head = _1;
        ListNode *_2 = new ListNode(2);
        _2->next = head;
        head = _2;
        ListNode *_2_1 = new ListNode(2);
        _2_1->next = head;
        head = _2_1;
        ListNode *_1_1 = new ListNode(1);
        _1_1->next = head;
        head = _1_1;
        REQUIRE(s.isPalindrome(head));
    }
    list_free(head);
}
