#include "ContainsDuplicateII.hpp"

#include <unordered_map>
using namespace std;

bool ContainsDuplicateII::containsNearbyDuplicate(vector<int>& nums, int k)
{
    unordered_map<int, int> records;
    for (int i = 0; i < nums.size(); i++) {
        if (records.find(nums[i]) != records.end() && i - records[nums[i]] <= k)
            return true;
        else
            records[nums[i]] = i;
    }

    return false;
}