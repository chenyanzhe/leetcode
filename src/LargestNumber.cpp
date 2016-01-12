#include "LargestNumber.hpp"

#include <algorithm>
#include <functional>
using namespace std;

string LargestNumber::largestNumber(vector<int>& nums)
{
  if (nums.empty()) {
    return "";
  }

  vector<string> num_strs;

  for (const auto& n : nums) {
    num_strs.push_back(to_string(n));
  }

  return largestNumber(num_strs);
}

string LargestNumber::largestNumber(vector<string>& nums)
{
  string result;
  function<bool (const string&, const string&)> comp;
  comp = [&comp](const string & a, const string & b) {
    int sza = a.size();
    int szb = b.size();

    if (sza > szb) {
      return !comp(b, a);
    }

    // len(a) <= len(b)
    // [--a--][----b----]
    // [----b----][--a--]
    // a[0 : sza - 1] v.s. b[0 : sza - 1]
    // b[0 : szb - sza - 1] v.s. b[sza : szb - 1]
    // b[szb - sza : szb - 1] v.s. a[0 : sza - 1]

    for (int i = 0, j = 0; i < sza && j < sza; i++, j++) {
      if (a[i] > b[j]) {
        return true;
      }

      if (a[i] < b[j]) {
        return false;
      }
    }

    for (int i = 0, j = sza; i < szb - sza && j < szb; i++, j++) {
      if (b[i] > b[j]) {
        return true;
      }

      if (b[i] < b[j]) {
        return false;
      }
    }

    for (int i = szb - sza, j = 0; i < szb && j < sza; i++, j++) {
      if (b[i] > a[j]) {
        return true;
      }

      if (b[i] < a[j]) {
        return false;
      }
    }

    return false;
  };
  sort(nums.begin(), nums.end(), comp);

  if (nums[0] == "0") {
    return "0";
  }

  for (auto ns : nums) {
    result += ns;
  }

  return result;
}
