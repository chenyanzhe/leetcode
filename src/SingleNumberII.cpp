#include "SingleNumberII.hpp"

int SingleNumberII::singleNumber(vector<int> &nums) {
    int a = 0, b = 0;
    for (auto c : nums) {
        int _a = (a & ~b & ~c) | (~a & b & c);
        int _b = (~a & b & ~c) | (~a & ~b & c);
        a = _a;
        b = _b;
    }
    return a | b;
}