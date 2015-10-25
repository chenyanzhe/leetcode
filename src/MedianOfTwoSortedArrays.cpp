#include "MedianOfTwoSortedArrays.hpp"

#include <algorithm>
using namespace std;

double MedianOfTwoSortedArrays::findMedianSortedArrays(vector<int>& A, vector<int>& B)
{
    if (A.empty() && B.empty())
        return 0;

    return findMedianSortedArrays(A.data(), A.size(), B.data(), B.size());
}

double MedianOfTwoSortedArrays::findMedianSortedArrays(int A[], int m, int B[], int n)
{
    int total = m + n;
    if (total & 1)
        return findKth(A, m, B, n, total / 2 + 1);
    else
        return (findKth(A, m, B, n, total / 2) + findKth(A, m, B, n, total / 2 + 1)) / 2;
}

double MedianOfTwoSortedArrays::findKth(int A[], int m, int B[], int n, int k)
{
    if (m > n)
        return findKth(B, n, A, m, k);

    if (m == 0)
        return B[k-1];

    if (k == 1)
        return min(A[0], B[0]);

    int i = min(k / 2, m);
    int j = k - i;
    
    if (A[i - 1] < B[j - 1])
        return findKth(A + i, m - i, B, n, k - i);
    else if (A[i - 1] > B[j - 1])
        return findKth(A, m, B + j, n - j, k - j);
    else
        return A[i - 1];
}