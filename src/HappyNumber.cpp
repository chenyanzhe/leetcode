#include "HappyNumber.hpp"

#include <unordered_set>
using namespace std;

bool HappyNumber::isHappy(int n)
{
    unordered_set<int> records;
    while (n != 1 && records.count(n) == 0) {
        records.insert(n);
        int next = 0;
        while (n > 0) {
            int d = n % 10;
            n = n / 10;
            next += d * d;
        }
        n = next;
    }
    return n == 1;
}
