In addition to all that we have learned so far, the STL also provides a number of algorithms that can be used on a range of elements. These algorithms are implemented as functions that usually utilize iterators. In this task, we will look at some of the most commonly used algorithms. There are many more algorithms available in the STL, and you can find a complete list [here](https://en.cppreference.com/w/cpp/algorithm).
We highly encourage you to explore the STL algorithms yourself and try to use them in your code! They are useful and can save you a lot of time and effort.

#### 1. `std::sort()`
The [`std::sort()`](https://en.cppreference.com/w/cpp/algorithm/sort) algorithm is used to sort a range of elements. It is implemented as a function template of an `O(n log n)` sorting algorithm (most likely [introsort](https://en.wikipedia.org/wiki/Introsort)), and the syntax is as follows:
```cpp
std::sort(start_iterator, end_iterator, comparator);
```
The first two arguments are iterators that define the range of elements to be sorted. The third argument is an optional comparator used to compare two elements. If no comparator is provided, the elements are sorted in ascending order by default. The comparator can be a function pointer or a functor. As you might expect, this function requires a Random Access Iterator to enable sorting in any order.
```cpp
// Sort a vector of integers in ascending order
std::vector<int> v1 = {5, 2, 4, 3, 1};
std::sort(v1.begin(), v1.end());
// v = {1, 2, 3, 4, 5}

// Sort a vector of integers in descending order
std::vector<int> v2 = {5, 2, 4, 3, 1};
std::sort(v2.begin(), v2.end(), std::greater<>());
// v = {5, 4, 3, 2, 1}

// Sort a vector of strings in ascending order by length
std::vector<std::string> v3 = {"abc", "a", "ab"};
std::sort(v3.begin(), v3.end(), [](const std::string &a, const std::string &b) {
    return a.size() < b.size();
});
// v = {"a", "ab", "abc"}
```

#### 2. `std::reverse()`
[`std::reverse()`](https://en.cppreference.com/w/cpp/algorithm/reverse) is used to reverse a range of elements. It is implemented as a template of a straightforward `O(n)` algorithm with the following syntax:
```cpp
std::reverse(start_iterator, end_iterator);
```
The two arguments are iterators that define the range of elements to be reversed. This function requires a Bidirectional Iterator.
```cpp
std::vector<int> v = {1, 2, 3, 4, 5};
std::reverse(v.begin(), v.end());
// v = {5, 4, 3, 2, 1}
```

#### 3. `std::find()`
[`std::find()`](https://en.cppreference.com/w/cpp/algorithm/find) is used to find the first occurrence of a value in a range of elements. It is implemented as a function template of an `O(n)` algorithm and has the following syntax:
```cpp
std::find(start_iterator, end_iterator, value);
```
The first two arguments are iterators that define the range of elements to be searched within. The third argument is the value to be searched for. If the value is found, an iterator to the first occurrence of the value is returned. Otherwise, an iterator to the end of the range is returned. When the function doesn't require an execution policy, an Input Iterator is used; otherwise, it's a Forward Iterator. 
```cpp
std::vector<int> v = {1, 2, 3, 4, 5};
auto it = std::find(v.begin(), v.end(), 3);
if (it != v.end()) {
    std::cout << "Found " << *it << std::endl;
} else {
    std::cout << "Not found" << std::endl;
}
```

#### 4. `std::max_element()` and `std::min_element()`
[`std::max_element()`](https://en.cppreference.com/w/cpp/algorithm/max_element) and [`std::min_element()`](https://en.cppreference.com/w/cpp/algorithm/min_element) are used to find the maximum and minimum elements in a range of elements, respectively. They both have `O(n)` complexity and share the following interface:
```cpp
std::max_element(start_iterator, end_iterator, comparator);
std::min_element(start_iterator, end_iterator, comparator);
```
The first two arguments are iterators that define the range of elements to be searched within. The third argument is an optional comparator used to compare two elements. If no comparator is provided, the elements are compared using the `<` operator by default. As you may have guessed, these functions require a Forward Iterator.
```cpp
std::vector<int> v = {1, 2, 3, 4, 5};
auto max_it = std::max_element(v.begin(), v.end());
auto min_it = std::min_element(v.begin(), v.end());
std::cout << "Max: " << *max_it << std::endl;
std::cout << "Min: " << *min_it << std::endl;
```

#### 5. `std::fill()`
[`std::fill()`](https://en.cppreference.com/w/cpp/algorithm/fill) is used to fill a range of elements with a specific value. It runs in `O(n)` time complexity, equivalent to the time it takes to traverse the entire array and change the elements . The syntax is quite simple:
```cpp
std::fill(start_iterator, end_iterator, value);
```
The first two arguments are iterators that define the range of elements to be filled. The third argument is the value to be used for filling. A Forward Iterator is required for this function.
```cpp
std::vector<int> v = {1, 2, 3, 4, 5};
std::fill(v.begin(), v.end(), 0);
// v = {0, 0, 0, 0, 0}
```

There is also a header called [`<numeric>`](https://en.cppreference.com/w/cpp/header/numeric) that contains a number of useful algorithms for numeric operations.

For example, [`std::accumulate()`](https://en.cppreference.com/w/cpp/algorithm/accumulate) is used to calculate the sum of a range of elements. It is implemented as a simple linear `O(n)` traversal, with the following syntax:
```cpp
std::accumulate(start_iterator, end_iterator, initial_value);
```
This function requires Input Iterators, and the first two arguments are iterators that define the range to be summed. The third argument is the initial value of the sum. Be aware of the accumulator type, as it may overflow if the sum is too large. For example, to sum a range of integers, you can use `0LL` as the initial value to avoid overflow.
```cpp
std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
long long sum = std::accumulate(v.begin(), v.end(), 0LL);
std::cout << "Sum: " << sum << std::endl;
```

Finally, let's get some practice with these algorithms. Your task is to implement a function that takes a vector of integers and returns the sum of elements with values between two provided values: `lowerBound` and `upperBound`.
