#ifndef MAX_POINTS_ON_A_LINE_HPP_
#define MAX_POINTS_ON_A_LINE_HPP_

#include <vector>

using namespace std;

struct Point {
    int x;
    int y;

    Point() : x(0), y(0) {}

    Point(int a, int b) : x(a), y(b) {}
};

class MaxPointsOnALine {
public:
    int maxPoints(vector<Point> &points);

private:
    int generateGCD(int a, int b);
};

#endif // MAX_POINTS_ON_A_LINE_HPP_