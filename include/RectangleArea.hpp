#ifndef RECTANGLE_AREA_HPP_
#define RECTANGLE_AREA_HPP_

class RectangleArea {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H);

private:
    enum RELATION {
        OVERLAP, DISJOINT, CONTAIN
    };

    RELATION decide(int a1, int a2, int b1, int b2);

    int area(int a1, int a2, int b1, int b2);

    int share(int a1, int a2, int b1, int b2);
};

#endif // RECTANGLE_AREA_HPP_
