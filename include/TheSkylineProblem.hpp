#ifndef THE_SKYLINE_PROBLEM_HPP_
#define THE_SKYLINE_PROBLEM_HPP_

#include <vector>
#include <utility>
using namespace std;

class TheSkylineProblem {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings);
private:
    enum NODE_TYPE {LEFT, RIGHT};
    struct node {
        int x, y;
        NODE_TYPE type;
        node(int _x, int _y, NODE_TYPE _type) : x(_x), y(_y), type(_type) {}
    };
};

#endif // THE_SKYLINE_PROBLEM_HPP_
