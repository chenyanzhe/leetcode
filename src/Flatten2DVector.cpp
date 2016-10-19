#include "Flatten2DVector.hpp"

Vector2D::Vector2D(vector<vector<int>> &vec2d) : rowId(0), colId(0), vec2d(vec2d) {
}

int Vector2D::next() {
    if (hasNext()) {
        return vec2d[rowId][colId++];
    }
    return -1;
}

bool Vector2D::hasNext() {
    if (rowId >= vec2d.size()) return false;
    while (rowId < vec2d.size() && colId >= vec2d[rowId].size()) {
        rowId++;
        colId = 0;
    }
    return rowId < vec2d.size();
}
