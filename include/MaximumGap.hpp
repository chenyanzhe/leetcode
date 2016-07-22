#ifndef MAXIMUM_GAP_HPP_
#define MAXIMUM_GAP_HPP_

#include <vector>

using namespace std;

class MaximumGap {
public:
    int maximumGap(vector<int> &nums);

private:
    int getNthDigit(int num, int n);
};

#endif // MAXIMUM_GAP_HPP_
