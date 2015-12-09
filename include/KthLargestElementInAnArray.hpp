#ifndef KTH_LARGEST_ELEMENT_IN_AN_ARRAY_HPP_
#define KTH_LARGEST_ELEMENT_IN_AN_ARRAY_HPP_

#include <vector>
using namespace std;

class KthLargestElementInAnArray {
public:
    int findKthLargest(vector<int>& nums, int k);

private:
    int findKthLargest(vector<int>& nums, int i, int j, int k);
    int partition(vector<int>& nums, int begin, int end);
};

#endif // KTH_LARGEST_ELEMENT_IN_AN_ARRAY_HPP_
