#ifndef DESIGN_HIT_COUNTER_HPP_
#define DESIGN_HIT_COUNTER_HPP_

#include <list>
#include <vector>

using namespace std;

class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter();

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp);

    void hitBuckets(int timestamp);

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp);

    int getHitsBuckets(int timestamp);

private:
    list<int> hits;
    vector<int> hits_buckets;
    vector<int> time_buckets;
};

#endif // DESIGN_HIT_COUNTER_HPP_