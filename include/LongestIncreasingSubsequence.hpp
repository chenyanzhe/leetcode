#ifndef LONGEST_INCREASING_SUBSEQUENCE_HPP_
#define LONGEST_INCREASING_SUBSEQUENCE_HPP_

#include <vector>

using namespace std;

class LongestIncreasingSubsequence {
public:
    int lengthOfLIS(vector<int> &nums);

private:
    int lengthOfLIS_DynamicProgramming(vector<int> &nums);

    int lengthOfLIS_BinarySearch(vector<int> &nums);

    int binarySearch(vector<int> &tails, int end, int target);
};

#endif // LONGEST_INCREASING_SUBSEQUENCE_HPP_