#ifndef CREATE_MAXIMUM_NUMBER_HPP_
#define CREATE_MAXIMUM_NUMBER_HPP_

#include <vector>
using namespace std;

class CreateMaximumNumber
{
public:
  vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k);
private:
  vector<int> mergeNums(vector<int>& nums1, vector<int>& nums2);
  bool greaterThan(vector<int>& nums1, int i, vector<int>& nums2, int j);
  void helper(vector<int>& nums, vector<vector<int>>& dp, int n, int m);
};

#endif // CREATE_MAXIMUM_NUMBER_HPP_
