#include "catch.hpp"

#include "RotateList.hpp"

TEST_CASE("Rotate List") {
	RotateList s;

	ListNode* l = nullptr;

	SECTION("Sample tests") {
		ListNode* item = nullptr;

		// (1 -> 2 -> 3 -> 4 -> 5)
	    item = new ListNode(5); item->next = l; l = item;
	    item = new ListNode(4); item->next = l; l = item;
	    item = new ListNode(3); item->next = l; l = item;
	    item = new ListNode(2); item->next = l; l = item;
	    item = new ListNode(1); item->next = l; l = item;

	    l = s.rotateRight(l, 2);

	    // should be (4 -> 5 -> 1 -> 2 -> 3)
    	item = l;
    	REQUIRE_FALSE(item == nullptr); REQUIRE(item->val == 4); item = item->next;
    	REQUIRE_FALSE(item == nullptr); REQUIRE(item->val == 5); item = item->next;
    	REQUIRE_FALSE(item == nullptr); REQUIRE(item->val == 1); item = item->next;
    	REQUIRE_FALSE(item == nullptr); REQUIRE(item->val == 2); item = item->next;
    	REQUIRE_FALSE(item == nullptr); REQUIRE(item->val == 3); item = item->next;
    	REQUIRE(item == nullptr);
	}

	list_free(l);
}
