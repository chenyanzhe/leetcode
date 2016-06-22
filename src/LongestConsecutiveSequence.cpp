#include "LongestConsecutiveSequence.hpp"

#include <unordered_map>
#include <algorithm>
using namespace std;

int LongestConsecutiveSequence::longestConsecutive(vector<int>& nums)
{
  unordered_map<int, bool> records;
  int result = 1;

  for (auto n : nums)
    records[n] = false;

  for (auto n : nums) {
    if (records[n])
      continue;

    int length = 1;

    for (int i = n + 1; records.find(i) != records.end(); i++) {
      records[i] = true;
      length++;
    }

    for (int i = n - 1; records.find(i) != records.end(); i--) {
      records[i] = true;
      length++;
    }

    result = max(result, length);
  }

  return result;
}
