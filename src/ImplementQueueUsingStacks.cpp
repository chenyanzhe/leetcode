#include "ImplementQueueUsingStacks.hpp"

void ImplementQueueUsingStacks::push(int x) {
    while (!primary.empty()) {
        backup.push(primary.top());
        primary.pop();
    }

    primary.push(x);

    while (!backup.empty()) {
        primary.push(backup.top());
        backup.pop();
    }
}

void ImplementQueueUsingStacks::pop(void) {
    if (!primary.empty())
        primary.pop();
}

int ImplementQueueUsingStacks::peek(void) {
    if (!primary.empty())
        return primary.top();

    return 0;
}

bool ImplementQueueUsingStacks::empty(void) {
    return primary.empty();
}