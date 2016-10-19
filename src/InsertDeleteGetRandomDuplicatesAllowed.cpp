#include "InsertDeleteGetRandomDuplicatesAllowed.hpp"

#include <cstdlib>

using namespace std;

RandomizedCollection::RandomizedCollection() : count(0) {

}

bool RandomizedCollection::insert(int val) {
    lookup[val].insert(count);
    if (count < store.size())
        store[count] = val;
    else
        store.push_back(val);
    count++;
    return lookup[val].size() == 1;
}

bool RandomizedCollection::remove(int val) {
    if (lookup.find(val) == lookup.end() || lookup[val].empty())
        return false;
    count--;
    auto it = lookup[val].begin();
    int idx = *it;
    lookup[val].erase(it);
    if (lookup[val].empty())
        lookup.erase(val);
    if (idx < count) {
        lookup[store[count]].erase(count);
        lookup[store[count]].insert(idx);
        swap(store[count], store[idx]);
    }
    return true;
}

int RandomizedCollection::getRandom() {
    return store[rand() % count];
}
