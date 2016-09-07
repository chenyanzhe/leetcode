#include "ImplementQueueUsingStacks.hpp"

void ImplementQueueUsingStacks::push(int x) {
    backup.push(x);
}

void ImplementQueueUsingStacks::pop(void) {
    if (primary.empty()) {
        while (!backup.empty()) {
            primary.push(backup.top());
            backup.pop();
        }
    }
    if (!primary.empty())
        primary.pop();
}

int ImplementQueueUsingStacks::peek(void) {
    if (primary.empty()) {
        while (!backup.empty()) {
            primary.push(backup.top());
            backup.pop();
        }
    }
    if (!primary.empty())
        return primary.top();
    return 0;
}

bool ImplementQueueUsingStacks::empty(void) {
    return backup.empty() && primary.empty();
}