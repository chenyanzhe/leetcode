#ifndef COPY_LIST_WITH_RANDOM_POINTER_HPP_
#define COPY_LIST_WITH_RANDOM_POINTER_HPP_

struct RandomListNode {
    int label;
    RandomListNode *next, *random;

    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

class CopyListWithRandomPointer {
public:
    RandomListNode *copyRandomList(RandomListNode *head);

private:
    void duplicate(RandomListNode *head);

    void fixRandom(RandomListNode *head);

    RandomListNode *unwind(RandomListNode *head);
};

#endif // COPY_LIST_WITH_RANDOM_POINTER_HPP_