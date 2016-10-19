#ifndef FLATTEN_2D_VECTOR_HPP_
#define FLATTEN_2D_VECTOR_HPP_

#include <vector>

using namespace std;

class Vector2D {
public:
    Vector2D(vector<vector<int> > &vec2d);

    int next();

    bool hasNext();

private:
    int rowId;
    int colId;
    vector<vector<int>> vec2d;
};

#endif // FLATTEN_2D_VECTOR_HPP_