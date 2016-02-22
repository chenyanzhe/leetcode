#ifndef MINIMUM_PATH_SUM_HPP_
#define MINIMUM_PATH_SUM_HPP_

#include <vector>
using namespace std;

class MinimumPathSum
{
public:
  int minPathSum(vector<vector<int>>& grid);
private:
  int minPathSum_Raw(vector<vector<int>>& grid);
  int minPathSum_Optimized(vector<vector<int>>& grid);
};

#endif // MINIMUM_PATH_SUM_HPP_
