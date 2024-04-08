#include "../include/Cache.h"

LRUCache::LRUCache(std::size_t capacity) : capacity(capacity) {}

std::string LRUCache::get(const std::string& key) {
    auto found = mapper.find(key);
    if (found == mapper.end()) {
        return "Key: <" + key + "> not found!\n";
    }
    lru.splice(lru.begin(), lru, found->second);
    return found->second->second;
}

void LRUCache::put(const std::string& key, const std::string& value) {
    auto found = mapper.find(key);
    if (found != mapper.end()) {
        found->second->second = value;
        lru.splice(lru.begin(), lru, found->second);
        return;
    }
    if (lru.size() == capacity) {
        mapper.erase(lru.back().first);
        lru.pop_back();
    }
    lru.emplace_front(key, value);
    mapper[key] = lru.begin();
}

int main() {
    LRUCache cache(4);
    cache.put("1", "one");
    cache.put("2", "two");
    cache.put("3", "three");
    cache.put("4", "four");
    std::cout << cache.get("1") << '\n'; // one
    cache.put("5", "five");
    std::cout << cache.get("2") << '\n'; // Key: <2> not found!
    return 0;
}