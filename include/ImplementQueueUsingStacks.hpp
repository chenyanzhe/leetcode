#ifndef IMPLEMENT_QUEUE_USING_STACKS_HPP_
#define IMPLEMENT_QUEUE_USING_STACKS_HPP_

#include <stack>

using namespace std;

class ImplementQueueUsingStacks {
public:
    // Push element x to the back of queue.
    void push(int x);

    // Removes the element from in front of queue.
    void pop(void);

    // Get the front element.
    int peek(void);

    // Return whether the queue is empty.
    bool empty(void);

private:
    stack<int> primary;
    stack<int> backup;
};

#endif // IMPLEMENT_QUEUE_USING_STACKS_HPP_