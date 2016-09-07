#include "TheSkylineProblem.hpp"

#include <set>
#include <algorithm>

using namespace std;

vector<pair<int, int>> TheSkylineProblem::getSkyline(vector<vector<int>> &buildings) {
    vector<Point> cps;
    for (auto &b : buildings) {
        cps.emplace_back(b[0], b[2], true);
        cps.emplace_back(b[1], b[2], false);
    }
    sort(cps.begin(), cps.end(), PointOrder());

    vector<pair<int, int>> ret;
    int curMax = 0;
    multiset<int> q;
    q.insert(0);

    for (auto &p : cps) {
        if (p.start) {
            q.insert(p.height);
            if (p.height > curMax) {
                curMax = p.height;
                ret.emplace_back(p.x, p.height);
            }
        } else {
            q.erase(q.find(p.height));
            if (p.height == curMax && *q.rbegin() != curMax) {
                curMax = *q.rbegin();
                ret.emplace_back(p.x, curMax);
            }
        }
    }

    return ret;
}
