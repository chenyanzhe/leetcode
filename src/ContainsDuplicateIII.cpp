#include "ContainsDuplicateIII.hpp"

#include <set>
using namespace std;

bool ContainsDuplicateIII::containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
{
    if (k <= 0 || t < 0 || nums.empty()) return false;

    set<long> window; // use long to handle overflow
    for (int i = 0; i < nums.size(); i++) {
        if (i > k) window.erase(nums[i-k -1]);
        auto lb = window.lower_bound((long)nums[i] - t);
        if (lb != window.end() && *lb <= (long)nums[i] + t)
            return true;
        window.insert(nums[i]);
    }
    return false;
}
