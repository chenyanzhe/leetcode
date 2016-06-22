#include "CreateMaximumNumber.hpp"

vector<int> CreateMaximumNumber::maxNumber(vector<int>& nums1,
    vector<int>& nums2, int k)
{
  int sz1 = nums1.size();
  int sz2 = nums2.size();

  if (sz1 + sz2 == k)
    return mergeNums(nums1, nums2);

  vector<int> ret;

  for (int a = 0; a <= k; a++) {
    int b = k - a;

    if (a > sz1 || b > sz2)
      continue;

    vector<int> va = maxNumber(nums1, a);
    vector<int> vb = maxNumber(nums2, b);
    vector<int> t = mergeNums(va, vb);

    if (greaterThan(t, 0, ret, 0))
      ret = t;
  }

  return ret;
}

vector<int> CreateMaximumNumber::maxNumber(vector<int>& nums, int k)
{
  int sz = nums.size();

  if (sz == 0 || sz <= k)
    return nums;

  vector<int> ret;
  int i = 0;

  while (k > 0) {
    int j = sz - k;
    int idx = maxNumIdx(nums, i, j);
    ret.push_back(nums[idx]);
    i = idx + 1;
    k--;
  }

  return ret;
}

int CreateMaximumNumber::maxNumIdx(vector<int>& nums, int i, int j)
{
  int ret = i;

  for (int k = i + 1; k <= j; k++) {
    if (nums[k] > nums[ret])
      ret = k;
  }

  return ret;
}

vector<int> CreateMaximumNumber::mergeNums(vector<int>& nums1,
    vector<int>& nums2)
{
  int sz1 = nums1.size();
  int sz2 = nums2.size();
  int sz  = sz1 + sz2;
  vector<int> nums(sz, 0);

  for (int i = 0, j = 0, r = 0; r < sz; r++)
    nums[r] = greaterThan(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];

  return nums;
}

bool CreateMaximumNumber::greaterThan(vector<int>& nums1, int i,
                                      vector<int>& nums2, int j)
{
  while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
    i++;
    j++;
  }

  return j == nums2.size() || (i < nums1.size() && nums1[i] > nums2[j]);
}
