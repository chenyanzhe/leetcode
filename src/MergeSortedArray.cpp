#include "MergeSortedArray.hpp"

void MergeSortedArray::merge(vector<int>& nums1, int m, vector<int>& nums2,
                             int n)
{
  vector<int> done;
  done.reserve(m + n);
  int i, j, k;

  for (i = 0, j = 0, k = 0; i < m + n; i++) {
    if (j == m)
      done[i] = nums2[k++];
    else if (k == n)
      done[i] = nums1[j++];
    else {
      int v1 = nums1[j];
      int v2 = nums2[k];

      if (v1 < v2)
        done[i] = nums1[j++];
      else
        done[i] = nums2[k++];
    }
  }

  for (i = 0; i < m + n; i++)
    nums1[i] = done[i];
}
