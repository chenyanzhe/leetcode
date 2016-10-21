#include "MaxPointsOnALine.hpp"

#include <unordered_map>

using namespace std;

int MaxPointsOnALine::maxPoints(vector<Point> &points) {
    if (points.size() <= 2) return points.size();

    unordered_map<int, unordered_map<int, int>> lookup;

    int ret = 0;

    for (int i = 0; i < points.size(); i++) {
        lookup.clear();
        int overlap = 0, mp = 0;
        for (int j = i + 1; j < points.size(); j++) {
            int x = points[i].x - points[j].x;
            int y = points[i].y - points[j].y;
            if (x == 0 && y == 0) {
                overlap++;
                continue;
            }
            int gcd = generateGCD(x, y);
            if (gcd != 0) {
                x /= gcd;
                y /= gcd;
            }

            if (lookup.count(x) && lookup[x].count(y)) {
                lookup[x][y]++;
            } else {
                lookup[x][y] = 1;
            }
            mp = max(mp, lookup[x][y]);
        }
        ret = max(ret, mp + overlap + 1);
    }

    return ret;
}

int MaxPointsOnALine::generateGCD(int a, int b) {
    if (b == 0) return a;
    return generateGCD(b, a % b);
}
