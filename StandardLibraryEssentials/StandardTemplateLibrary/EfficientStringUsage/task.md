A container you're already familiar with is [`std::string`](https://en.cppreference.com/w/cpp/string/basic_string). It's a structure used to store character sequences. Why don't we use `std::vector<char>` instead? The two share many similarities: for example, you can access their elements by index, and both automatically manage memory. In addition, they share methods like `push_back()`, `pop_back()`, `insert()`, `erase()`, `size()`, and `empty()`. 

The main difference is that `std::string` has many methods that are specific to strings, like `find()`, `substr()`, `replace()`, etc.
Moreover, `std::string` supports the `+` operator, which is used to concatenate strings, and guarantees null termination, allowing you to use the `c_str()` method to get a pointer to the null-terminated string.
Additionally, `std::string` features many constructors, enabling the creation of a string from a character, a substring, a pointer to a null-terminated string, a pointer to a string, a range of characters, etc.

In general, `std::string` is a more convenient way to work with strings than `std::vector<char>`.

It's a useful container, but there are a few things that can cause performance slowdowns. So in this lesson, you will learn how to use `std::string` efficiently.

First, similar to `std::vector`, you can use the `reserve()` method to reserve a certain number of characters if the required capacity is known.

<div class="hint">
  Also, there is a feature called **Small String Optimization**. This means that if your string is small enough, it will be stored in the stack instead of the heap. For more details, you can read this article: https://giodicanio.com/2023/04/26/cpp-small-string-optimization/.
</div>

When you need to pass a string to a function, it's often beneficial to pass it by const reference. If you don't pass it this way, the string will be copied. For example, if you want to print a string, you can pass it by const reference:

```cpp
void print(const std::string& str) {
    std::cout << str << '\n';
}

int main() {
    std::string str = "Imagine a very long string here that will take a loooooot of time to copy";
    print(str);
}
```

As you may remember from the previous module, move semantics provide a more efficient way to manage your resources. When passing a string and the initial object is no longer needed, consider using `std::move()`.

```cpp
class person {
private:
    std::string person_name;
    std::string person_surname;
    
public:
    person(std::string name, std::string surname)
    : person_name(std::move(name)), person_surname(std::move(surname)) {}
};

void createPerson() {
    std::string name = "Alex";
    std::string surname = "Johns";
    person great_guy(name, surname);
}
```

In C++, there is a special type called [`std::string_view`](https://en.cppreference.com/w/cpp/string/basic_string_view). It's a non-owning view of a string, meaning it doesn't store the string itself, but only a pointer to the string. It's convenient when you want to pass a string to a function or a container but have no intention of changing it and wish to avoid copying the string. It's also useful when you want to get a substring.

```cpp
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
```

Note that there is no implicit conversion from `std::string_view` to `std::string`. You can either use the `std::string` constructor from `std::string_view`:
```cpp 
std::string_view sv = "Hello, World!";
std::string str {sv};
```
or use
```cpp
static_cast<std::string>(your_sv_object)
```
if you want to get a string.

Also, it is better to pass a `std::string_view` object by value, since it is a small structure consisting only of a pointer and a size. For a more detailed explanation, you can read [this](https://quuxplusone.github.io/blog/2021/11/09/pass-string-view-by-value/).

The main methods of `std::string` are:
* `size()` — returns the size of the string
* `empty()` — returns `true` if the string is empty
* `clear()` — clears the string
* `push_back()` — adds a character to the end of the string
* `pop_back()` — removes the last character from the string
* `replace()` — replaces a character at a given position
* `substr()` — returns a substring of the string
* `find()` — finds a substring in the string

Like `std::vector`, `std::string` has methods to insert and erase characters at a given position; however, they can be inefficient. Since these methods have linear complexity, it's best to avoid using them if possible.
* `insert()` — inserts a character at a given position. It can also insert a substring at a given position.
* `erase()` — erases a character or a substring at a given position.

Your task is to implement a program that checks if an input string is a palindrome. A palindrome is a word, number, phrase, or other sequence of characters that reads the same forwards and backward, ignoring spaces, punctuation, and capitalization.

We encourage you to implement the `preprocess` function, which will perform preprocessing of the input string. This should be formatted in such a way that checking if it is a palindrome becomes easier.

The `isPalindrome` function should return `true` if the input string is a palindrome and `false` otherwise.
