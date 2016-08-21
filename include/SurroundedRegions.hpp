#ifndef SURROUNDED_REGIONS_HPP_
#define SURROUNDED_REGIONS_HPP_

#include <vector>

using namespace std;

class SurroundedRegions {
public:
    void solve(vector<vector<char>> &board);

private:
    void bfs(vector<vector<char>> &board, int i, int j, int m, int n);
};

#endif // SURROUNDED_REGIONS_HPP_
