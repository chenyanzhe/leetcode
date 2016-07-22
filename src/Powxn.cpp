#include "Powxn.hpp"

double Powxn::myPow(double x, int n) {
    double ans = 1;

    if (n < 0) {
        x = 1 / x;
        n = -(n + 1); // avoid overflow
        ans *= x;
    }

    while (n > 0) {
        if (n & 1)
            ans *= x;

        x *= x;
        n >>= 1;
    }

    return ans;
}
