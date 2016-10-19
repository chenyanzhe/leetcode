#ifndef INSERT_DELETE_GET_RANDOM_DUPLICATES_ALLOWED_HPP_
#define INSERT_DELETE_GET_RANDOM_DUPLICATES_ALLOWED_HPP_

#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection();

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val);

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val);

    /** Get a random element from the collection. */
    int getRandom();

private:
    unordered_map<int, unordered_set<int>> lookup;
    vector<int> store;
    int count;
};

#endif // INSERT_DELETE_GET_RANDOM_DUPLICATES_ALLOWED_HPP_