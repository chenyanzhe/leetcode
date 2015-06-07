#include "TwoSum.hpp"

#include <unordered_map>
using namespace std;

vector<int> TwoSum::twoSum(vector<int> &nums, int target)
{
  unordered_map<int, int> indexMap;
  vector<int> ans;

  for (size_t i = 0; i < nums.size(); i++) {
    int val = nums[i];
    if (indexMap.find(target - val) != indexMap.end()) {
      ans.push_back(indexMap[target - val]);
      ans.push_back((int) i + 1);
      return ans;
    } else {
      indexMap[val] = (int) i + 1;
    }
  }
  return ans;
}
