#include "catch.hpp"

#include "ConvertSortedListToBinarySearchTree.hpp"

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

TEST_CASE("Convert Sorted List to Binary Search Tree") {
	ConvertSortedListToBinarySearchTree s;

	TreeNode *root = nullptr;
	ListNode *head = nullptr;

	SECTION("Sample test") {
		ListNode* item = nullptr;

    	// list (1 -> 2 -> 3 -> 4)
    	item = new ListNode(4); item->next = head; head = item;
    	item = new ListNode(3); item->next = head; head = item;
    	item = new ListNode(2); item->next = head; head = item;
    	item = new ListNode(1); item->next = head; head = item;

		root = s.sortedListToBST(head);

		/*
		 *    2                  3
		 *   / \                / \
		 *  1   3      or      2   4
		 *       \            /
		 *        4          1
		 */
		vector<string> expected {"2 1 # # 3 # 4 # # ", "3 2 1 # 4 # # "};
		REQUIRE_FALSE(find(expected.begin(), expected.end(), tree_serialize(root)) == expected.end());
	}

	tree_free(root);
	list_free(head);
}