#include "HappyNumber.hpp"

#include <unordered_set>

using namespace std;

bool HappyNumber::isHappy(int n) {
    return isHappyTwoPointers(n);
}

int HappyNumber::digitSquareSum(int n) {
    int sum = 0, tmp;
    while (n) {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }
    return sum;
}

bool HappyNumber::isHappyHash(int n) {
    unordered_set<int> records;

    while (n != 1 && records.count(n) == 0) {
        records.insert(n);
        n = digitSquareSum(n);
    }

    return n == 1;
}

bool HappyNumber::isHappyTwoPointers(int n) {
    int slow, fast;
    slow = fast = n;
    do {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
    } while (slow != fast);

    return slow == 1;
}