#ifndef WIGGLE_SORT_II_HPP_
#define WIGGLE_SORT_II_HPP_

#include <vector>

using namespace std;

class WiggleSortII {
public:
    void wiggleSort(vector<int> &nums);

private:
    int m(int idx, int n);
};

#endif // WIGGLE_SORT_II_HPP_