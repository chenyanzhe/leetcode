#ifndef SPLIT_ARRAY_WITH_EQUAL_SUM_HPP_
#define SPLIT_ARRAY_WITH_EQUAL_SUM_HPP_

#include <vector>
#include <set>

using namespace std;

class SplitArrayWithEqualSum {
public:
    bool splitArray(vector<int>& nums);

private:
    bool splitEqual(vector<int>& agg, int i, int j, set<int>& v);
};

#endif // SPLIT_ARRAY_WITH_EQUAL_SUM_HPP_