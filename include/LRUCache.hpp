#ifndef LRU_CACHE_HPP_
#define LRU_CACHE_HPP_

#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
private:
    struct CacheNode {
        int key;
        int val;

        CacheNode(int k, int v) : key(k), val(v) {}
    };

public:
    LRUCache(int capacity);

    int get(int key);

    void set(int key, int value);

private:
    list<CacheNode> cacheList;
    unordered_map<int, list<CacheNode>::iterator> cacheMap;
    int capacity;
};

#endif // LRU_CACHE_HPP_