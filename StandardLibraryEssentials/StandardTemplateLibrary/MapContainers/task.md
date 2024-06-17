Another form of associative container is [`std::map`](http://en.cppreference.com/w/cpp/container/map). It is similar to `std::set`, but it stores key-value pairs. You can think of it as a dictionary. 

The keys are unique and, by default, sorted in ascending order. They are immutable, so you cannot change them. 
The values are not sorted and can be duplicated. 

You can always define your own sorting criteria by providing a custom comparator.

Compared with `std::set` and `std::multiset`, `std::map` and `std::multimap` provide direct access to their elements using the `operator[]` and `at()` methods. However, be aware of the following behavior: if the key is not found, `operator[]` will insert a new element with the specified key and a default value. In contrast, the `at()` method will throw an exception if the key is not found.

```cpp
std::map<std::string, int> people;
people.insert(std::make_pair("John", 25));
people.insert({"Jane", 20});
people["John"] = 30; // will overwrite the previous value
people["Alex"] = 15; // will insert a new element
people["John"] += 5; // will increase the value
std::cout << "Number of people: " << people.size() << std::endl;
```

[`std::multimap`](http://en.cppreference.com/w/cpp/container/multimap) offers the same functionality as `std::map`, but it allows duplicate keys.

Note that searching with `find()` can only be performed using a key. There is no way to search by a value other than iterating through the whole container.

Both `std::set` and `std::map` are not stored in a contiguous memory block. Therefore, while the following code works for `std::vector`:

```cpp
std::vector<int> v = {1, 2, 3};
int* p = &v[0];
p += 1;
std::cout << *p << std::endl; // will print 2
```

in the case of associative containers, it will lead to undefined behavior:

```cpp
std::map<int, int> m = {{1, 2}, {3, 4}};
std::pair<const int, int>* p2 = &*m.begin();
p2 += 1;
std::cout << p2->first << ' ' << p2->second << std::endl; // Undefined behavior
```

Under the hood, both the set and map containers are built upon a [Red-black tree](https://en.wikipedia.org/wiki/Red–black_tree), a balanced binary search tree data structure. This allows them to achieve logarithmic complexity for insertion and search operations.

As a task, you need to implement a function that counts the appearances of each letter in a text. The function should return a `std::map` with letters as keys and the number of appearances as values. The letters should be sorted in alphabetical order. The function should be case-insensitive; i.e., the letters "A" and "a" should be considered the same. The function should also ignore punctuation marks and numbers.
