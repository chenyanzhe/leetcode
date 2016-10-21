#include "FractionToRecurringDecimal.hpp"

#include <unordered_map>
#include <cstdlib>

using namespace std;

string FractionToRecurringDecimal::fractionToDecimal(int numerator, int denominator) {
    int64_t n = numerator;
    int64_t d = denominator;

    if (n == 0) return "0";

    string res;
    if (n < 0 ^ d < 0) res += '-';

    n = abs(n);
    d = abs(d);

    res += to_string(n / d);

    if (n % d == 0) return res;

    res += '.';

    unordered_map<int64_t, size_t> lookup;

    for (int64_t r = n % d; r; r = r % d) {
        if (lookup.count(r)) {
            res.insert(lookup[r], 1, '(');
            res += ')';
            break;
        }

        lookup[r] = res.size();

        r *= 10;

        res += to_string(r / d);
    }

    return res;
}
