#ifndef FIND_MEDIAN_FROM_DATA_STREAM_HPP_
#define FIND_MEDIAN_FROM_DATA_STREAM_HPP_

#include <queue>

using namespace std;

class MedianFinder {
private:
    priority_queue<long> small, large;

public:
    // Adds a number into the data structure.
    void addNum(int num);

    // Returns the median of current data stream
    double findMedian();
};

#endif // FIND_MEDIAN_FROM_DATA_STREAM_HPP_