#include "LRUCache.hpp"

LRUCache::LRUCache(int capacity) : capacity(capacity) {
}

int LRUCache::get(int key) {
    if (cacheMap.find(key) == cacheMap.end())
        return -1;

    cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
    cacheMap[key] = cacheList.begin();

    return cacheList.begin()->val;
}

void LRUCache::set(int key, int value) {
    if (cacheMap.find(key) == cacheMap.end()) {
        if (cacheList.size() == capacity) {
            cacheMap.erase(cacheList.back().key);
            cacheList.pop_back();
        }
        cacheList.emplace_front(key, value);
        cacheMap[key] = cacheList.begin();
    } else {
        cacheMap[key]->val = value;
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        cacheMap[key] = cacheList.begin();
    }
}