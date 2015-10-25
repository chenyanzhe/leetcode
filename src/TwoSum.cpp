#include "TwoSum.hpp"

#include <unordered_map>
using namespace std;

vector<int> TwoSum::twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> mapping;
    vector<int> result;

    // preprocess
    for (int i = 0; i < nums.size(); i++)
        mapping[nums[i]] = i;

    for (int i = 0; i < nums.size(); i++) {
        int gap = target - nums[i];
        if (mapping.find(gap) != mapping.end() && mapping[gap] > i) {
            result.push_back(i + 1);
            result.push_back(mapping[gap] + 1);
            break;
        }
    }
    
    return result;
}
