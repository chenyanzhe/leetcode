#include "DivideTwoIntegers.hpp"

#include <climits>
#include <cstdint>

using namespace std;

int DivideTwoIntegers::divide(int dividend, int divisor) {
    int64_t a = (dividend >= 0) ? dividend : -(int64_t) dividend;
    int64_t b = (divisor >= 0) ? divisor : -(int64_t) divisor;

    int64_t ret = 0, shift = 31;
    while (shift >= 0) {
        if (a >= (b << shift)) {
            a -= (b << shift);
            ret += (1L << shift);
        }
        shift--;
    }

    ret = ((dividend ^ divisor) >> 31) ? -ret : ret;

    return ret > INT_MAX ? INT_MAX : ret;
}
