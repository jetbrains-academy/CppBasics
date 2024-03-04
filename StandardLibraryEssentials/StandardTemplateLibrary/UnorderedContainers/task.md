Is there any way to make such a container that will have `O(1)` complexity for insertion, deletion and search? Sounds like magic, right?
Well, it is not. STL provides `std::unordered_set` and `std::unordered_map` containers that are implemented using [hash tables](https://en.wikipedia.org/wiki/Hash_table).

Hash table is a data structure that uses [hash function](https://en.wikipedia.org/wiki/Hash_function) to map keys to buckets. Whenever you want to insert or search for an element, you apply hash function to the key and get the bucket number. Then you insert or search for the element in the bucket. Standard library provides `std::hash` function for basic types, and you can define your own hash function for your custom types.
It is very efficient for insertion, deletion and search operations. They all have **amortized** `O(1)` complexity. But sometimes hashes of different keys can be the same. This is called [collision](https://en.wikipedia.org/wiki/Hash_table#Collision_resolution). In this situation, the whole table needs to be rehashed. This is why unordered container's methods can perform in `O(n)` time in the worst case. 
The only drawback comparing to the basic set and map is that it does not preserve the order of elements. So, if you need to iterate over elements in some order, you should use `std::set` or `std::map` instead.

There are a few functions for buckets manipulation:
* `bucket_count()` - returns the number of buckets
* `bucket_size(n)` - returns the number of elements in the bucket `n`
* `bucket(k)` - returns the bucket number for the key `k`
* `load_factor()` - returns the average number of elements per bucket
* `max_load_factor()` - returns the maximum load factor
* `rehash(n)` - sets the number of buckets to `n` or more

When you need a custom hash function, you can define it like this:
```cpp
#include <iostream>
#include <unordered_set>
#include <string>

struct my_type {
private:
    int x;
    int y;

public:
    my_type(const int x, const int y) : x(x), y(y) {};
    
    bool operator==(const my_type& other) const {
        return x == other.x && y == other.y;
    }

    friend struct my_hash;
};

struct my_hash {
    std::size_t operator()(const my_type& t) const {
        return std::hash<int>()(t.x) ^ std::hash<int>()(t.y);
    }
};

int main() {
    std::unordered_set<my_type, my_hash> s;
    s.emplace(1, 2);
}
```

There are multi-versions of these containers: `std::unordered_multiset`, `std::unordered_multimap`. They allow storing multiple elements with the same key.

As an example, let's take a look at the following code:
```cpp
#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    std::unordered_set<std::string> set;
    set.insert("Greetings, traveler!");
    set.insert("How are you?");
    set.insert("Come join us!");
    
    if (set.find("How are you?") != set.end()) {
        std::cout << "Found!" << std::endl;
    }
    
    // If you're using C++20 or above, you can use this:
    
    // if (set.contains("How are you?")) {
    //     std::cout << "Found!" << std::endl;
    // }
    
    // print all elements, order is not guaranteed
    for (const auto& s : set) {
        std::cout << s << std::endl;
    }
}
```

You need to implement a small caching system. It is defined in `/include/Cache.h` file. Since [cache](https://en.wikipedia.org/wiki/Cache_(computing)) is very fast type of storage, in which we will frequently search data, `std::unordered_map` is a good choice for this task.

You need to implement the following methods:
 - `put(key, value)` - adds a new key-value pair to the cache.
 - `get(key)` - returns the string associated with the key or empty string if the key is not found.
 - `remove(key)` - removes the key-value pair from the cache.
 - `print_element(key)` - prints the key-value pair (in format: `<key>: <value>`) or `<key> not found` if the key is not found.
 - `print_cache()` - prints all key-value pairs in the cache (in format: `<key>: <value>`).
