#include "SqrtX.hpp"

#include <cstdint>

using namespace std;

int SqrtX::mySqrt(int x) {
    int64_t l = 1, r = x;

    while (l + 1 < r) {
        int64_t m = l + (r - l) / 2;
        if (m * m < x)
            l = m;
        else
            r = m;
    }

    return r * r <= x ? r : l;
}