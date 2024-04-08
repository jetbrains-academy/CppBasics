The container that you already know is [`std::string`](https://en.cppreference.com/w/cpp/string/basic_string). It's a structure used to store character sequences. Why don't we use `std::vector<char>` instead? They are similar in some ways, for example, you can access the elements by index, both automatically manage memory and you have methods like `push_back()`, `pop_back()`, `insert()`, `erase()`, `size()`, `empty()` in both. 

The main difference is that `std::string` has a lot of methods that are specific to strings, like `find()`, `substr()`, `replace()`, etc.
Moreover, `std::string` supports `+` operator, which is used to concatenate strings. And null termination is guaranteed, so you can use `c_str()` method to get a pointer to the null-terminated string.
In addition, `std::string` has a lot of constructors, so you can create a string from a character, a substring, a pointer to a null-terminated string, a pointer to a string, a range of characters, etc.

In general, `std::string` is a more convenient way to work with strings than `std::vector<char>`.

It's a useful container, but there are a few things that can cause performance drawdown. So in this lesson you will learn how to use `std::string` efficiently.

At first, the same as with `std::vector`, you can use `reserve()` method to reserve a certain number of characters, if the required capacity is known.

<div class="hint">
  Also, there is a feature called **Small String Optimization**. It means that if your string is small enough, it will be stored in the stack instead of the heap. For more details, you can read this article: https://giodicanio.com/2023/04/26/cpp-small-string-optimization/
</div>

When you need to pass string to a function, in many cases it would be great to pass it by const reference. If you don't pass it this way, the string will be copied. For example, if you want to print a string, you can pass it by const reference:

```cpp
void print(const std::string& str) {
    std::cout << str << '\n';
}

int main() {
    std::string str = "Imagine a very long string here that will take a loooooot of time to copy";
    print(str);
}
```

As you remember from the previous module, move semantics are a great way to manage your resources in a more efficient way. When you want to pass a string, and you won't need an initial object anymore, consider using `std::move()`.

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

In C++, there is a special type called [`std::string_view`](https://en.cppreference.com/w/cpp/string/basic_string_view). It's a non-owning view of a string. It means that it doesn't store the string itself, but only a pointer to the string. It's convenient when you want to pass a string to a function or a container, but you are not going to change it and don't want to copy the string. It's also useful when you want to get a substring.

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

The main methods of `std::string` are:
* `size()` - returns the size of the string
* `empty()` - returns `true` if the string is empty
* `clear()` - clears the string
* `push_back()` - adds a character to the end of the string
* `pop_back()` - removes the last character from the string
* `replace()` - replaces a character at a given position
* `substr()` - returns a substring of the string
* `find()` - finds a substring in the string

As well as `std::vector`, `std::string` has methods to insert and erase characters at a given position, that are inefficient. They have linear complexity, so you should avoid using them if it is possible.
* `insert()` - inserts a character at a given position. It can also insert a substring at a given position.
* `erase()` - erases a character or a substring at a given position.

Your task would be to implement a program to check if an input string is a palindrome. A palindrome is a word, number, phrase, or other sequence of characters that reads the same forward and backward, ignoring spaces, punctuation, and capitalization.

We encourage you to implement `preprocess` function that will perform preprocessing of the input string so that it will be formatted in a way that will make it easier to check if it is a palindrome.

`isPalindrome` function should return `true` if the input string is a palindrome and `false` otherwise.
