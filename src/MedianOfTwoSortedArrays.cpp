#include "MedianOfTwoSortedArrays.hpp"

using namespace std;

double MedianOfTwoSortedArrays::findMedianSortedArrays(vector<int> &A,
                                                       vector<int> &B) {
    int m = A.size();
    int n = B.size();

    if (m == 0 && n == 0)
        return 0;

    int l = (m + n + 1) >> 1;
    int r = (m + n + 2) >> 1;
    return (findKth(A.data(), m, B.data(), n, l)
            + findKth(A.data(), m, B.data(), n, r)) / 2.0;
}

double MedianOfTwoSortedArrays::findKth(int A[], int m, int B[], int n, int k) {
    if (m > n)
        return findKth(B, n, A, m, k);

    if (m == 0)
        return B[k - 1];

    if (k == 1)
        return min(A[0], B[0]);

    int i = min(k / 2, m);
    int j = min(k / 2, n);

    if (A[i - 1] < B[j - 1])
        return findKth(A + i, m - i, B, n, k - i);
    else
        return findKth(A, m, B + j, n - j, k - j);
}
