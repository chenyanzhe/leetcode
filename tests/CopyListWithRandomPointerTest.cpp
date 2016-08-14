#include "catch.hpp"

#include "CopyListWithRandomPointer.hpp"

TEST_CASE("Copy List with Random Pointer") {
    CopyListWithRandomPointer s;
    SECTION("Sample test") {
        RandomListNode *_1 = new RandomListNode(1);
        RandomListNode *_2 = new RandomListNode(2);
        RandomListNode *_3 = new RandomListNode(3);
        RandomListNode *_4 = new RandomListNode(4);
        _1->next = _2;
        _2->next = _3;
        _3->next = _4;
        _1->random = _3;
        _2->random = _1;
        _4->random = _2;

        RandomListNode *r = s.copyRandomList(_1);
        RandomListNode *node = r;

        REQUIRE_FALSE(node == nullptr);
        REQUIRE(node->label == 1);
        REQUIRE_FALSE(node->random == nullptr);
        REQUIRE(node->random->label == 3);

        node = node->next;
        REQUIRE_FALSE(node == nullptr);
        REQUIRE(node->label == 2);
        REQUIRE_FALSE(node->random == nullptr);
        REQUIRE(node->random->label == 1);

        node = node->next;
        REQUIRE_FALSE(node == nullptr);
        REQUIRE(node->label == 3);
        REQUIRE(node->random == nullptr);

        node = node->next;
        REQUIRE_FALSE(node == nullptr);
        REQUIRE(node->label == 4);
        REQUIRE_FALSE(node->random == nullptr);
        REQUIRE(node->random->label == 2);

        node = node->next;
        REQUIRE(node == nullptr);
    }
}