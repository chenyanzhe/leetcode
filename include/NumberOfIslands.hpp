#ifndef NUMBER_OF_ISLANDS_HPP_
#define NUMBER_OF_ISLANDS_HPP_

#include <vector>
using namespace std;

class NumberOfIslands {
public:
    int numIslands(vector<vector<char>>& grid);
private:
    void bfs(vector<vector<char>>& grid, int i, int j);
};

#endif // NUMBER_OF_ISLANDS_HPP_
