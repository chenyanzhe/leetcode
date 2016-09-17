#include "SqrtX.hpp"

#include <cstdint>

using namespace std;

int SqrtX::mySqrt(int x) {
    if (x <= 0) return 0;
    int64_t l = 1;
    int64_t r = x;
    while (l < r) {
        int64_t m = l + (r - l + 1) / 2;
        if (m * m == (int64_t) x)
            return (int) m;
        if (m * m < (int64_t) x)
            l = m;
        else
            r = m - 1;
    }
    return (int) l;
}