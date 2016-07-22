#ifndef IMPLEMENT_STACK_USING_QUEUES_HPP_
#define IMPLEMENT_STACK_USING_QUEUES_HPP_

#include <queue>

using namespace std;

class ImplementStackUsingQueues {
public:
    // Push element x onto stack.
    void push(int x);

    // Removes the element on top of the stack.
    void pop();

    // Get the top element.
    int top();

    // Return whether the stack is empty.
    bool empty();

private:
    queue<int> primary;
    queue<int> backup;
};

#endif // IMPLEMENT_STACK_USING_QUEUES_HPP_
