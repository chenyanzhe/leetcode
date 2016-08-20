#ifndef SUMMARY_RANGES_HPP_
#define SUMMARY_RANGES_HPP_

#include <vector>
#include <string>

using namespace std;

class SummaryRanges {
public:
    vector<string> summaryRanges(vector<int> &nums);

private:
    void addRange(int start, int end, vector<string> &res);
};

#endif // SUMMARY_RANGES_HPP_
