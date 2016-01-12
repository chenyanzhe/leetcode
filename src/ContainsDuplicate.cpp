#include "ContainsDuplicate.hpp"

#include <unordered_set>
using namespace std;

bool ContainsDuplicate::containsDuplicate(vector<int>& nums)
{
  unordered_set<int> records;

  for (auto d : nums) {
    if (records.find(d) != records.end()) {
      return true;
    } else {
      records.insert(d);
    }
  }

  return false;
}
