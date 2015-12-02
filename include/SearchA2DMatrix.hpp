#ifndef SEARCH_A_2D_MATRIX_HPP_
#define SEARCH_A_2D_MATRIX_HPP_

#include <vector>
using namespace std;

class SearchA2DMatrix {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target);
private:
	bool searchMatrix(vector<vector<int>>& matrix, int target, int begin, int end);
	int getValue(vector<vector<int>>& matrix, int i);
};

#endif // SEARCH_A_2D_MATRIX_HPP_
