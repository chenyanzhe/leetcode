#ifndef FIND_MINIMUM_IN_ROTATED_SORTED_ARRAY_II_HPP_
#define FIND_MINIMUM_IN_ROTATED_SORTED_ARRAY_II_HPP_

#include <vector>
using namespace std;

class FindMinimumInRotatedSortedArrayII {
public:
    int findMin(vector<int>& nums);
private:
    int findMin(vector<int>& nums, int begin, int end);
};

#endif // FIND_MINIMUM_IN_ROTATED_SORTED_ARRAY_II_HPP_