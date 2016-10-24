#ifndef CREATE_MAXIMUM_NUMBER_HPP_
#define CREATE_MAXIMUM_NUMBER_HPP_

#include <vector>

using namespace std;

class CreateMaximumNumber {
public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k);

private:
    vector<int> findMaxKNumbers(vector<int> &nums, int k);

    vector<int> mergeNums(vector<int> &nums1, vector<int> &nums2);

    bool greaterThan(vector<int> &nums1, int i, vector<int> &nums2, int j);
};

#endif // CREATE_MAXIMUM_NUMBER_HPP_
