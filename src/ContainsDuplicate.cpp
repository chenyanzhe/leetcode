#include "ContainsDuplicate.hpp"

#include <unordered_set>
using namespace std;

bool ContainsDuplicate::containsDuplicate(vector<int>& nums)
{
  unordered_set<int> records;

  for (auto d : nums) {
    if (records.count(d)) return true;

    records.insert(d);
  }

  return false;
}
