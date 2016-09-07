#include "KthLargestElementInAnArray.hpp"

#include <queue>

using namespace std;

int KthLargestElementInAnArray::findKthLargest(vector<int> &nums, int k) {
    struct MinOrder {
        bool operator()(const int &a, const int &b) {
            return a > b;
        }
    };

    typedef priority_queue<int, vector<int>, MinOrder> MinHeap;
    MinHeap h;

    for (int i = 0; i < k; i++)
        h.push(nums[i]);
    for (int i = k; i < nums.size(); i++) {
        if (nums[i] > h.top()) {
            h.pop();
            h.push(nums[i]);
        }
    }

    return h.top();
}
