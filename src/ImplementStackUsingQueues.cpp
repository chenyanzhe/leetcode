#include "ImplementStackUsingQueues.hpp"

void ImplementStackUsingQueues::push(int x)
{
    while (!primary.empty()) {
        backup.push(primary.front());
        primary.pop();
    }
    primary.push(x);
    while (!backup.empty()) {
        primary.push(backup.front());
        backup.pop();
    }
}

void ImplementStackUsingQueues::pop()
{
    if (!empty()) primary.pop();
}

int ImplementStackUsingQueues::top()
{
    if (!empty()) return primary.front();
    else return 0;
}

bool ImplementStackUsingQueues::empty()
{
    return primary.empty();
}
