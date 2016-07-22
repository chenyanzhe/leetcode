#include "FractionToRecurringDecimal.hpp"

#include <vector>
#include <unordered_map>
#include <cstdlib>

using namespace std;

string FractionToRecurringDecimal::fractionToDecimal(int numerator,
                                                     int denominator) {
    if (numerator == 0)
        return "0";

    if (denominator == 0)
        return "";

    bool isNegative = (numerator < 0 && denominator > 0) || (numerator > 0 &&
                                                             denominator < 0);
    string result = isNegative ? "-" : "";
    result += helper(abs(static_cast<long>(numerator)),
                     abs(static_cast<long>(denominator)));
    return result;
}

string FractionToRecurringDecimal::helper(long numerator, long denominator) {
    long integral = numerator / denominator;
    numerator = numerator % denominator;

    if (numerator == 0)
        return to_string(integral);

    string result = to_string(integral) + ".";
    // INVARIANT: `numerator` is less than `denominator`
    vector<long> chains;
    unordered_map<long, string> records;
    unordered_map<long, long> extends;
    long target = numerator;

    while (true) {
        chains.push_back(target);
        long padding = 0;
        target *= 10;

        while (target / denominator == 0) {
            target *= 10;
            padding++;
        }

        long remain = target % denominator;
        records[chains.back()] = string(padding,
                                        '0') + to_string(target / denominator);;

        while (padding > 0) {
            target /= 10;
            extends[target] = chains.back();
            padding--;
        }

        if (remain == 0) {
            // case 0: the fractional part is NOT repeating
            for (auto d : chains)
                result += records[d];

            return result;
        } else if (records.count(remain)) {
            // case 1: `remain` is exactly in `chains`
            int i = 0;

            for (; chains[i] != remain; i++)
                result += records[chains[i]];

            result += "(";

            for (; i < chains.size(); i++)
                result += records[chains[i]];

            result += ")";
            return result;
        } else if (extends.count(remain)) {
            // case 2: `remain` is 10x (100x, 1000x ...) than some value in `chains`
            long base = extends[remain];
            int borrow = 0;

            while (remain > base) {
                remain /= 10;
                borrow++;
            }

            int i = 0;

            for (; chains[i] != base; i++)
                result += records[chains[i]];

            result += records[base].substr(0, borrow);
            result += "(";
            result += records[base].substr(borrow);

            for (i = i + 1; i < chains.size(); i++)
                result += records[chains[i]];

            result += ")";
            return result;
        } else
            target = remain;
    }
}
