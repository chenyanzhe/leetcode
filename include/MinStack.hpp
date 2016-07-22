#ifndef MIN_STACK_HPP_
#define MIN_STACK_HPP_

#include <stack>

using namespace std;

class MinStack {
public:
    void push(int x);

    void pop();

    int top();

    int getMin();

private:
    stack<int> wholeStack;
    stack<int> minStack;
};

#endif // MIN_STACK_HPP_
