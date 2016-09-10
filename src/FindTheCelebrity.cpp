#include "FindTheCelebrity.hpp"

bool FindTheCelebrity::knows(int a, int b) {
    //TODO: should be injected by test suite
    return false;
}

int FindTheCelebrity::findCelebrity(int n) {
    int candidate = 0;
    for (int i = 1; i < n; i++) {
        if (knows(candidate, i))
            candidate = i;
    }

    for (int i = 0; i < n; i++) {
        if (i < candidate) {
            if (!knows(i, candidate) || knows(candidate, i))
                return -1;
        } else {
            if (!knows(i, candidate))
                return -1;
        }
    }

    return candidate;
}