#include "DesignHitCounter.hpp"

HitCounter::HitCounter() : hits_buckets(300, 0), time_buckets(300, 0) {

}

void HitCounter::hit(int timestamp) {
    hits.push_back(timestamp);
}

int HitCounter::getHits(int timestamp) {
    int start = timestamp > 300 ? timestamp - 300 + 1 : 1;
    while (!hits.empty() && timestamp - *(hits.begin()) >= 300)
        hits.pop_front();
    return hits.size();
}

void HitCounter::hitBuckets(int timestamp) {
    int index = timestamp % 300;
    if (time_buckets[index] != timestamp) {
        time_buckets[index] = timestamp;
        hits_buckets[index] = 1;
    } else {
        hits_buckets[index]++;
    }
}

int HitCounter::getHitsBuckets(int timestamp) {
    int total = 0;
    for (int i = 0; i < 300; i++)
        if (timestamp - time_buckets[i] < 300)
            total += hits_buckets[i];
    return total;
}


