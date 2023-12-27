The container that you already know is [`std::string`](https://en.cppreference.com/w/cpp/string/basic_string). It's a structure used to store character sequences. 
The main methods of `std::string` are:
* `size()` - returns the size of the string
* `empty()` - returns `true` if the string is empty
* `clear()` - clears the string
* `push_back()` - adds a character to the end of the string
* `pop_back()` - removes the last character from the string
* `insert()` - inserts a character at a given position. It can also insert a substring at a given position.
* `erase()` - erases a character at a given position. The same as `insert()`, this operation is quite slow.
* `replace()` - replaces a character at a given position
* `substr()` - returns a substring of the string
* `find()` - finds a substring in the string

It's a useful container, but there are a few things that can cause performance drawdown. So in this lesson you will learn how to use `std::string` efficiently.

#### Reserve
The same as with `std::vector`, you can use `reserve()` method to reserve a certain number of characters, if the required capacity is known.

#### Small String Optimization
The second thing you should know about `std::string` is that there is a feature called **Small String Optimization**. It means that if your string is small enough, it will be stored in the stack instead of the heap. It allows avoiding dynamic memory allocation and deallocation, which is time-consuming. The size of the string that is considered small enough is implementation defined, but it's usually 15 characters. So if your string is 15 characters or fewer, it will be stored in the stack. Otherwise, it will be stored in the heap.

#### Passing string by const reference
When you need to pass string to a function, in many cases it would be great to pass it by const reference. If you don't pass it this way, the string will be copied. For example, if you want to print a string, you can pass it by const reference:

```cpp
#include <iostream>
#include <string>

void print(const std::string& str) {
    std::cout << str << '\n';
}

int main() {
    std::string str = "Imagine a very long string here that will take a loooooot of time to copy";
    print(str);
}
```
Note that it is not the case in all situations. If you're going to modify the string, you can either pass it by value (this way the caller won't see the change) or by non-const reference (so that change would be made in an initial string). For more details, see [this article](https://belaycpp.com/2022/02/15/constant-references-are-not-always-your-friends/) 

#### Using move semantics
As you remember from the previous module, move semantics are a great way to manage your resources in a more efficient way. When you want to pass a string, and you won't need an initial object anymore, consider using `std::move()`.

```cpp
#include <iostream>
#include <string>

class person {
private:
    std::string person_name;
    std::string person_surname;
    
public:
    person(std::string name, std::string surname)
    : person_name(std::move(name)), person_surname(std::move(surname)) {}
};

int main() {
    std::string name = "Alex";
    std::string surname = "Johns";
    person great_guy(name, surname);
}
```

#### std::string_view
In C++, there is a special type called [`std::string_view`](https://en.cppreference.com/w/cpp/string/basic_string_view). It's a non-owning view of a string. It means that it doesn't store the string itself, but only a pointer to the string. It's convenient when you want to pass a string to a function or a container, but you are not going to change it and don't want to copy the string. It's also useful when you want to get a substring.

```cpp
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

int main() {
    std::string input1 = {"mindyourlegs"};
    std::string input2 = {"whenusingcpp"};
    std::vector<std::string_view> inputs {input1, input2};

    std::vector<std::string_view> substrings;
    for (std::size_t i = 0; i < inputs.size(); ++i) {
        const auto & string = inputs[i];
        for (std::size_t j = 0; j < string.size() - 2; ++j) {
            substrings.emplace_back(string.data() + j, 3);
        }
    }
    for (std::size_t i = 0; i < substrings.size(); ++i) {
        std::cout << substrings[i] << '\n';
    }
    return 0;
}
```

Note that there is no implicit conversion from `std::string_view` to `std::string`. You can either use `std::string` constructor from `std::string_view`:
```cpp 
std::string_view sv = "Hello, World!";
std::string str {sv};
```
or use
```cpp
static_cast<std::string>(your_sv_object)
```
if you want to get a string.

Also, it is better to pass `std::string_view` object by value, since it is a small structure consisting of only a pointer and a size. For more explanation why, you can read [this](https://quuxplusone.github.io/blog/2021/11/09/pass-string-view-by-value/).  
