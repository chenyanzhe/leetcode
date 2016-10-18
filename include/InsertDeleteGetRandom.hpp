#ifndef INSERT_DELETE_GET_RANDOM_HPP_
#define INSERT_DELETE_GET_RANDOM_HPP_

#include <unordered_map>
#include <vector>

using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet();

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val);

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val);

    /** Get a random element from the set. */
    int getRandom();

private:
    unordered_map<int, int> lookup;
    vector<int> store;
    int count;
};

#endif // INSERT_DELETE_GET_RANDOM_HPP_