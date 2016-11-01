#ifndef WIGGLE_SUBSEQUENCE_HPP_
#define WIGGLE_SUBSEQUENCE_HPP_

#include <vector>

using namespace std;

class WiggleSubsequence {
public:
    int wiggleMaxLength(vector<int> &nums);

private:
    int wiggleMaxLength_DynamicProgramming(vector<int> &nums);
    int wiggleMaxLength_Linear(vector<int> &nums);
};

#endif // WIGGLE_SUBSEQUENCE_HPP_
