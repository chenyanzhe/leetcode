#ifndef FIND_PEAK_ELEMENT_HPP_
#define FIND_PEAK_ELEMENT_HPP_

#include <vector>
using namespace std;

class FindPeakElement {
public:
    int findPeakElement(vector<int>& nums);
private:
    int findPeakElement(vector<int>& nums, int begin, int end);
};

#endif // FIND_PEAK_ELEMENT_HPP_