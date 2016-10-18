#include "InsertDeleteGetRandom.hpp"

#include <cstdlib>

using namespace std;

RandomizedSet::RandomizedSet() : count(0) {

}

bool RandomizedSet::insert(int val) {
    if (lookup.find(val) != lookup.end())
        return false;
    lookup[val] = count;
    if (count < store.size())
        store[count] = val;
    else
        store.push_back(val);
    count++;
    return true;
}

bool RandomizedSet::remove(int val) {
    if (lookup.find(val) == lookup.end())
        return false;
    count--;
    if (lookup[val] != count) {
        lookup[store[count]] = lookup[val];
        store[lookup[val]] = store[count];
    }
    lookup.erase(val);
    return true;
}

int RandomizedSet::getRandom() {
    return store[rand() % count];
}
