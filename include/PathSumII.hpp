#ifndef PATH_SUM_II_HPP_
#define PATH_SUM_II_HPP_

#include "TreeNode.hpp"

#include <vector>
using namespace std;

class PathSumII
{
private:
  vector<vector<int>> res;
public:
  vector<vector<int>> pathSum(TreeNode* root, int sum);
private:
  void pathSum(TreeNode* root, vector<int>& path, int sum);
};

#endif // PATH_SUM_II_HPP_
