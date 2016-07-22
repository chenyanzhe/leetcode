#ifndef COUNT_OF_SMALLER_NUMBERS_AFTER_SELF_HPP_
#define COUNT_OF_SMALLER_NUMBERS_AFTER_SELF_HPP_

#include <vector>

using namespace std;

class CountOfSmallerNumbersAfterSelf {
public:
    vector<int> countSmaller(vector<int> &nums);

private:
    int query(long index);

    void update(long index, int val);

    vector<int> bit;
};

#endif // COUNT_OF_SMALLER_NUMBERS_AFTER_SELF_HPP_
