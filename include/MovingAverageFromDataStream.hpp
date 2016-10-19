#ifndef MOVING_AVERAGE_FROM_DATA_STREAM_HPP_
#define MOVING_AVERAGE_FROM_DATA_STREAM_HPP_

#include <queue>

using namespace std;

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size);

    double next(int val);

private:
    int total;
    int size;
    deque<int> data;
};

#endif // MOVING_AVERAGE_FROM_DATA_STREAM_HPP_