#include "RectangleArea.hpp"

#include <algorithm>

using namespace std;

int RectangleArea::computeArea(int A, int B, int C, int D, int E, int F, int G,
                               int H) {
    RELATION x = decide(A, C, E, G);
    RELATION y = decide(B, D, F, H);

    if (x == DISJOINT || y == DISJOINT)
        return area(A, B, C, D) + area(E, F, G, H);

    int sx = share(A, C, E, G);
    int sy = share(B, D, F, H);

    if (x == CONTAIN && y == CONTAIN) {
        if (sx == C - A && sy == D - B)
            return area(E, F, G, H);

        if (sx == G - E && sy == H - F)
            return area(A, B, C, D);
    }

    return area(A, B, C, D) + area(E, F, G, H) - sx * sy;
}

RectangleArea::RELATION RectangleArea::decide(int a1, int a2, int b1, int b2) {
    if (a1 > b1)
        return decide(b1, b2, a1, a2);

    if (a2 <= b1)
        return DISJOINT;

    if (b2 <= a2)
        return CONTAIN;

    return OVERLAP;
}

int RectangleArea::area(int a1, int a2, int b1, int b2) {
    return (b1 - a1) * (b2 - a2);
}

int RectangleArea::share(int a1, int a2, int b1, int b2) {
    if (a1 > b1)
        return share(b1, b2, a1, a2);

    return min(a2, b2) - b1;
}
