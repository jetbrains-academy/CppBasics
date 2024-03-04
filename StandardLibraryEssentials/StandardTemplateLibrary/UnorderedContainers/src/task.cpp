#include "../include/Cache.h"

void Cache::put(const std::string& key, const std::string& value) {
    cache[key] = value;
}

std::string Cache::get(const std::string& key) const {
    if (cache.find(key) != cache.end()) {
        return cache.at(key);
    } else {
        return "";
    }
}

void Cache::remove(const std::string& key) {
    cache.erase(key);
}

void Cache::print_element(const std::string& key) const {
    if (cache.find(key) != cache.end()) {
        std::cout << key << ": " << cache.at(key) << std::endl;
    } else {
        std::cout << key << " not found" << std::endl;
    }
}

void Cache::print_cache() const {
    for (const auto& [key, value] : cache) {
        std::cout << key << ": " << value << std::endl;
    }
}

int main() {
    Cache cache;

    cache.put("Alice", "123-456-7890");
    cache.put("Bob", "234-567-8901");
    cache.put("Charlie", "345-678-9012");

    cache.print_cache(); // Order of elements most likely will differ to the one in the input

    cache.print_element("Alice");

    cache.remove("Alice");

    cache.print_element("Alice");

    return 0;
}