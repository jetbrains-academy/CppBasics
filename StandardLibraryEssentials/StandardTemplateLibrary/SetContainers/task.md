In addition to all the previously covered sequential containers, C++ also provides a number of associative containers. These containers are designed to store elements in a sorted order.

[`std::set`](http://en.cppreference.com/w/cpp/container/set) is a container that stores unique elements in sorted order. To store your own classes in `std::set`, you need to define a comparison operator. By default, the comparison function is `std::less`, which is equivalent to the `<` operator. 
The function should take two arguments of the same type as the elements of the set and return `true` if the first argument is less than the second (or simply should be on the left if your objects cannot be compared numerically), and `false` otherwise. The comparison function is usually defined as a `friend` of the class. The following example shows how to define a comparison function for a class `person`, which stores a person's name and age.

```cpp
class person {
public:
    person(std::string name, int age) : person_name(std::move(name)), person_age(age) {}
    std::string name() const { return person_name; }
    int age() const { return person_age; }
    friend bool operator<(const person& lhs, const person& rhs);
private:
    std::string person_name;
    int person_age;
};

bool operator<(const person& lhs, const person& rhs) {
    return lhs.name() < rhs.name();
}

int main() {
    std::set<person> people;
    people.insert(person("John", 25));
    people.insert(person("Jane", 20));
    people.insert(person("John", 25)); // duplicate won't be inserted
    std::cout << "Number of people: " << people.size() << std::endl;
    return 0;
}
```

[`std::multiset`](http://en.cppreference.com/w/cpp/container/multiset) offers the same functionality as `std::set` but allows for duplicate elements. It can be useful when you want to keep your set sorted, but duplicates are not a concern. The complexity of insertion and search operations remains logarithmic.

Unlike sequential containers, `std::set` and `std::multiset` do not provide direct access to their elements (no `at()` or `operator[]`). Elements can only be accessed through iterators.

The `find()` method returns an iterator to the element with the specified value. If the element is not found, the iterator will be equal to `end()`. The `count()` method returns the number of elements with the specified value, which would be either `0` or `1` for `std::set`, and any non-negative number for `std::multiset`.

`lower_bound()` and `upper_bound()` return iterators to the first element that is not less than (lower bound) or greater than (upper bound) the specified value. If the element is not found, the iterator will be equal to `end()`.

Consider using these containers when frequent search operations are expected, since they perform much faster than sequential containers.

Your task is to implement a function that takes a string, splits it into words, and returns a `std::set` of unique words. The words should be sorted in alphabetical order. The function should be case-insensitive, i.e., words such as "Hello" and "hello" should be considered the same. The function should also ignore punctuation marks and numbers. 

Try to find a way to convert characters to lowercase and to consider only letters. You might need to use an additional header. If you can't find a way, you can always use the hint below. 

<div class="hint">
  To check if a character is a letter, you can use the function <code>std::isalpha</code> from the <code>&lt;cctype&gt;</code> header. To convert a character to lowercase, you can use the function <code>std::tolower</code> from the same header.
</div>
