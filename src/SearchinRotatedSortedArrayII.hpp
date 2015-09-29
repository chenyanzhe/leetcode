#ifndef SEARCH_IN_ROTATED_SORTED_ARRAY_II_HPP_
#define SEARCH_IN_ROTATED_SORTED_ARRAY_II_HPP_

#include <vector>
using namespace std;

class SearchinRotatedSortedArrayII {
public:
	bool search(vector<int>& nums, int target);
private:
	bool partialSearch(vector<int>& nums, int p, int q, int target);
};

#endif // SEARCH_IN_ROTATED_SORTED_ARRAY_II_HPP_