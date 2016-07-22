#include "PartitionList.hpp"

ListNode *PartitionList::partition(ListNode *head, int x) {
    ListNode *l = nullptr, *lp = nullptr;
    ListNode *r = nullptr, *rp = nullptr;
    ListNode *p = head;

    while (p != nullptr) {
        if (p->val < x) {
            // insert in l
            if (lp == nullptr) {
                l = p;
                lp = p;
            } else {
                lp->next = p;
                lp = p;
            }
        } else {
            // insert in r
            if (rp == nullptr) {
                r = p;
                rp = p;
            } else {
                rp->next = p;
                rp = p;
            }
        }

        p = p->next;
    }

    // fix tail
    if (lp != nullptr)
        lp->next = nullptr;

    if (rp != nullptr)
        rp->next = nullptr;

    // merge l and r
    if (lp == nullptr)
        return r;
    else {
        lp->next = r;
        return l;
    }
}
