#include "Powxn.hpp"

#include <climits>

using namespace std;

double Powxn::myPow(double x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;

    if (n == INT_MIN) return myPow(x, n + 1) * (1 / x);

    bool negative = n < 0;
    if (negative) n *= -1;

    int k = n / 2;
    int l = n - k * 2;
    double t1 = myPow(x, k);
    double t2 = myPow(x, l);

    return negative ? 1 / (t1 * t1 * t2) : t1 * t1 * t2;
}
