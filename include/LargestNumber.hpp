#ifndef LARGEST_NUMBER_HPP_
#define LARGEST_NUMBER_HPP_

#include <string>
#include <vector>

using namespace std;

class LargestNumber {
public:
    string largestNumber(vector<int> &nums);

private:
    string largestNumber(vector<string> &nums);
};

#endif // LARGEST_NUMBER_HPP_
