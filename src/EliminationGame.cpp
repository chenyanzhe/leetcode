#include "EliminationGame.hpp"

int EliminationGame::lastRemaining(int n) {
    int remaining = n;
    int start = 1;
    int step = 2;
    bool left = true;

    while (remaining > 1) {
        remaining /= 2;
        if (left)
            start = start + step * remaining - step / 2;
        else
            start = start - step * remaining + step / 2;
        step *= 2;
        left = !left;
    }

    return start;
}