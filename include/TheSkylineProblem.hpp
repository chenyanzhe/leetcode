#ifndef THE_SKYLINE_PROBLEM_HPP_
#define THE_SKYLINE_PROBLEM_HPP_

#include <vector>
#include <utility>

using namespace std;

class TheSkylineProblem {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>> &buildings);

private:
    struct Point {
        int x;
        int height;
        bool start;

        Point(int x, int h, bool s) : x(x), height(h), start(s) {}
    };

    struct PointOrder {
        bool operator()(const Point &a, const Point &b) {
            if (a.x != b.x) return a.x < b.x;
            if (a.start && b.start) return a.height > b.height;
            if (!a.start && !b.start) return a.height < b.height;
            return a.start;
        }
    };
};

#endif // THE_SKYLINE_PROBLEM_HPP_
