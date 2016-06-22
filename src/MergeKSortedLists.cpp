#include "MergeKSortedLists.hpp"

#include <queue>
#include <vector>
using namespace std;

ListNode* MergeKSortedLists::mergeKLists(vector<ListNode*>& lists)
{
  struct OrderByVal {
    bool operator() (ListNode* a, ListNode* b)
    {
      return a->val > b->val;
    }
  };
  typedef priority_queue<ListNode*, vector<ListNode*>, OrderByVal> MergeQueue;
  MergeQueue q;
  ListNode dummy(0);
  ListNode* tail = &dummy;

  for (auto l : lists) {
    if (l)
      q.push(l);
  }

  while (!q.empty()) {
    tail->next = q.top();
    q.pop();
    tail = tail->next;

    if (tail->next)
      q.push(tail->next);
  }

  return dummy.next;
}
