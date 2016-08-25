#include "ValidPerfectSquare.hpp"

#include <cstdint>

using namespace std;

bool ValidPerfectSquare::isPerfectSquare(int num) {
    if (num <= 0) return false;

    int64_t l = 1, r = num;
    int64_t target = num;

    while (l + 1 < r) {
        int64_t m = l + (r - l) / 2;
        if (m * m == target) return true;

        if (m * m < target)
            l = m;
        else
            r = m;
    }

    return l * l == target || r * r == target;
}