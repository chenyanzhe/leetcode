#ifndef SEARCH_IN_ROTATED_SORTED_ARRAY_HPP_
#define SEARCH_IN_ROTATED_SORTED_ARRAY_HPP_

#include <vector>
using namespace std;

class SearchInRotatedSortedArray {
public:
  int search(vector<int>& nums, int target);
private:
  int partialSearch(vector<int>& nums, int p, int q, int target);
};

#endif // SEARCH_IN_ROTATED_SORTED_ARRAY_HPP_
