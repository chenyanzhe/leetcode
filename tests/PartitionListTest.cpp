#include "catch.hpp"

#include "PartitionList.hpp"

TEST_CASE("Partition List") {
	PartitionList s;

	ListNode* l = nullptr;

	SECTION("Sample test") {
		ListNode* item = nullptr; 
		
		// (1 -> 4 -> 3 -> 2 -> 5 -> 2)
	    item = new ListNode(2); item->next = l; l = item;
	    item = new ListNode(5); item->next = l; l = item;
	    item = new ListNode(2); item->next = l; l = item;
	    item = new ListNode(3); item->next = l; l = item;
	    item = new ListNode(4); item->next = l; l = item;
	    item = new ListNode(1); item->next = l; l = item;

	    l = s.partition(l, 3);

	    // should be (1 -> 2 -> 2 -> 4 -> 3 -> 5)
    	item = l;
    	REQUIRE_FALSE(item == nullptr); REQUIRE(item->val == 1); item = item->next;
    	REQUIRE_FALSE(item == nullptr); REQUIRE(item->val == 2); item = item->next;
    	REQUIRE_FALSE(item == nullptr); REQUIRE(item->val == 2); item = item->next;
    	REQUIRE_FALSE(item == nullptr); REQUIRE(item->val == 4); item = item->next;
    	REQUIRE_FALSE(item == nullptr); REQUIRE(item->val == 3); item = item->next;
    	REQUIRE_FALSE(item == nullptr); REQUIRE(item->val == 5); item = item->next;
    	REQUIRE(item == nullptr);
	}

	list_free(l);
}