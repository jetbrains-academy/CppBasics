Is there a way to create a container that has an `O(1)` complexity for insertion, deletion, and search? Sounds like magic, right?
Well, it is not. STL provides `std::unordered_set` and `std::unordered_map` containers that are implemented using [hash tables](https://en.wikipedia.org/wiki/Hash_table).

What distinguishes regular `std::set` and `std::map` from their unordered counterparts? Due to implementation details (which will be explained further), their main difference is the lack of a stable order of elements. There are iterators for such containers, but as you traverse the container using these iterators, you will most likely notice that the elements are not sorted in ascending order.
This, however, is a small price to pay for the `O(1)` complexity of the search, insertion, and deletion operations. 

The main methods of `std::unordered_set` and `std::unordered_map` include:
* `insert(value)` - inserts the element `value` into the container.
* `emplace(args...)` - constructs the element in-place.
* `erase(value)` - removes the element `value` from the container.
* `find(value)` - returns an iterator to the element `value` if it is found; otherwise, it returns `end()`.

A hash table is a data structure that uses a [hash function](https://en.wikipedia.org/wiki/Hash_function) to map keys to buckets. Whenever you want to insert or search for an element, you apply a hash function to the key and retrieve the bucket number. Then you insert or search for the element in the bucket. 

The standard library provides the `std::hash` function for basic types, and you can define your own hash function for any custom types.

<div class="hint">
  To be fair, all these methods have an amortized O(1) complexity, since sometimes hashes of different keys can be the same. This is called a collision: https://en.wikipedia.org/wiki/Hash_table#Collision_resolution. In such situations, the whole table needs to be rehashed, which is the reason why the methods of an unordered container can perform in O(n) time in the worst-case scenario.
</div>

There are a few functions for manipulating buckets:
* `bucket_count()` - returns the number of buckets.
* `bucket_size(n)` - returns the number of elements in bucket `n`
* `bucket(k)` - returns the bucket number for key `k`.
* `load_factor()` - returns the average number of elements per bucket.
* `max_load_factor()` - returns the maximum load factor.
* `rehash(n)` - sets the number of buckets to `n` or more.

When you need a custom hash function, you can define it like this:
```cpp
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

There are multi-versions of these containers: `std::unordered_multiset` and `std::unordered_multimap`. They allow storing multiple elements with the same key.

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

You need to implement a [cache](https://en.wikipedia.org/wiki/Cache_(computing)) system with an [LRU](https://en.wikipedia.org/wiki/Cache_replacement_policies#Least_recently_used_(LRU)) (Least Recently Used) policy. Its member functions are defined in the `/include/Cache.h` file. Since a cache is a very fast type of storage, you will need to use hashing to implement it. First, define a structure inside the `/include/Cache.h` file that will store key-value pairs. Then, define another structure that will store the key and an iterator to the corresponding element in the list. After defining these structures, you can implement the cache operations in `task.cpp`.

<div class="hint">
  The author's solution uses an `std::list` consisting of `std::pair` elements of key + value and an `std::unordered_map` with key + value being an iterator to the element of the previously defined list. 
</div>

The cache should have the following methods:
* `LRUCache(size_t capacity)` - a constructor that sets the maximum number of elements in the cache.
* `void put(const std::string& key, const std::string& value)` - inserts the key-value pair into the cache. If the cache is full, it should remove the least recently used element.
* `std::string get(const std::string& key)` - returns the value associated with the key. If the key is not found, it returns `std::nullptr`.
