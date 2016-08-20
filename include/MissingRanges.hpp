#ifndef MISSING_RANGES_HPP_
#define MISSING_RANGES_HPP_

#include <string>
#include <vector>

using namespace std;

class MissingRanges {
public:
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper);

private:
    void addRange(int left, int right, vector<string> &res);
};

#endif // MISSING_RANGES_HPP_