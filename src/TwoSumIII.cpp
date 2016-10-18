#include "TwoSumIII.hpp"

void TwoSumIII::add(int number) {
    lookup[number]++;
}

bool TwoSumIII::find(int value) {
    for (auto p : lookup) {
        int gap = value - p.first;
        if (lookup.find(gap) == lookup.end()) continue;
        if (gap != p.first || lookup[gap] > 1) return true;
    }
    return false;
}
