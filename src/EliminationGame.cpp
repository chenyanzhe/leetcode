#include "EliminationGame.hpp"

int EliminationGame::lastRemaining(int n) {
    int l = 1, r = n;
    bool reverse = false;
    int nums = n;
    int step = 2;

    while (nums > 1) {
        int jumps = nums % 2 ? nums / 2 + 1 : nums / 2;
        if (!reverse) {
            r = l + (jumps - 1) * step;
            if (nums % 2) r -= step / 2;
            else r += step / 2;
            l = r;
        } else {
            r = l - (jumps - 1) * step;
            if (nums % 2) r += step / 2;
            else r -= step / 2;
            l = r;
        }
        nums /= 2;
        step *= 2;
        reverse = !reverse;
    }

    return l;
}