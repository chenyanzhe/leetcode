#include "MergeKSortedLists.hpp"

#include <queue>
#include <vector>
using namespace std;

ListNode* MergeKSortedLists::mergeKLists(vector<ListNode*>& lists)
{
  auto compareFunc = [](ListNode* a, ListNode* b) { return a->val > b->val; };
  typedef priority_queue<ListNode*, vector<ListNode*>, decltype(compareFunc)> ListNodeQ;

  ListNodeQ lnq(compareFunc);

  ListNode* head = nullptr;
  ListNode* tail = nullptr;

  for (auto l : lists)
    if (l) lnq.push(l);

  if (lnq.empty()) return head;

  head = lnq.top(); lnq.pop();
  tail = head;
  if (tail->next) lnq.push(tail->next);
  tail->next = nullptr;

  while (!lnq.empty()) {
    tail->next = lnq.top(); lnq.pop();
    tail = tail->next;
    if (tail->next) lnq.push(tail->next);
    tail->next = nullptr;
  }

  return head;
}
