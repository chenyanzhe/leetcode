#ifndef MERGE_K_SORTED_LISTS_HPP_
#define MERGE_K_SORTED_LISTS_HPP_

#include "ListNode.hpp"

#include <vector>

using namespace std;

class MergeKSortedLists {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists);
};

#endif // MERGE_K_SORTED_LISTS_HPP_
