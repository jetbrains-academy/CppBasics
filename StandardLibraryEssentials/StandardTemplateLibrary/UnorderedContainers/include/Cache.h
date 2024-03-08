#ifndef CPPBASICS_CACHE_H
#define CPPBASICS_CACHE_H
#include <iostream>
#include <string>
#include <unordered_map>

class Cache {
public:
    void put(const std::string& key, const std::string& value);
    std::string get(const std::string& key) const;
    void remove(const std::string& key);
    void print_element(const std::string& key) const;
    void print_cache() const;

private:
    std::unordered_map<std::string, std::string> cache;
};

#endif //CPPBASICS_CACHE_H
