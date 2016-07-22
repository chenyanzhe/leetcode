#include "BitwiseANDOfNumbersRange.hpp"

int BitwiseANDOfNumbersRange::rangeBitwiseAnd(int m, int n) {
    int result = 0;
    int base = 1;

    while (m != 0) {
        if (m == n && m % 2)
            result += base;

        m /= 2;
        n /= 2;
        base *= 2;
    }

    return result;
}
