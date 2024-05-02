At times, you will need to handle various types of template parameters differently. 

For example, you may want to create a function that works with any type. However, if the type is a pointer, you would prefer to follow an alternative way. Fortunately, with template specialization, you can create a special version of the function for pointers, as well as for any other type. To do so, you need to write a function implementation with a defined type, like this:
```cpp
template <typename T>
void print(T value) {
    std::cout << value << std::endl;
}

template <>
void print<int*>(int* value) {
    std::cout << *value << std::endl;
}

int main() {
    int a = 5;
    int* b = &a;
    print(a); // prints 5
    print(b); // prints the value of the pointer
    return 0;
}
```

When the compiler encounters any call to a template function, it first checks for a specialized version of the function for the argument's type. If such a version exists, it will employ it; otherwise, it will use the general version.

There is a technique called metaprogramming, which allows you to write code that generates other code using templates and template specialization. Since it is a complex topic, we will not cover it in this course, but you can find more information about it in the [C++ documentation](https://en.cppreference.com/w/cpp/meta). However, there is a feature called "type traits" that can be helpful in some cases. Type traits are a set of classes that provide information about types at compile time. You can use them to check if a type has a specific property, like being a pointer or reference. You can find more information about type traits in the [C++ documentation](https://en.cppreference.com/w/cpp/header/type_traits).

Since each specialization requires a separate implementation, it may not always be the best solution. In many cases, you can try to find any common type property and use it's checker, like the `std::is_pointer` function to check if the type is a pointer and handle it within the general function. This way, you can avoid code duplication and make the code more readable.
```cpp
#include <type_traits>
template <typename T>
void print(T value) {
    if (std::is_pointer<T>::value) {
        std::cout << *value << std::endl;
    } else {
        std::cout << value << std::endl;
    }
}
```

If the number of parameters is unknown, you can use variadic templates. This allows you to create a function that can take any number of arguments of any type. The syntax is a bit more complex, but it is still quite simple:
```cpp
template <typename T>
T sum(T t) {
    return t;
}

template <typename T, typename... Args>
T sum(T first, Args... args) {
    return first + sum(args...);
}
```
In this case, the function takes the first argument and then calls itself recursively with the rest of the arguments. The recursion stops when there are no more arguments left. Note that there should be a base case for the recursion — the first function in our example — otherwise, the compiler will generate an error.

Your task would be to create a template function to display information about `DataPair` objects that you've implemented in the previous task. The function should take a `DataPair` object and print the values of its fields. If the type of the field is a pointer, it should print the value of the pointer, otherwise simply print the value. 

Moreover, if two fields are of the same type, the function should print the string `<Typename> DataPair:  <first>, <second>`, where `<Typename>` is the common type name. Since the class name is not a part of the standard C++ library, let's specify it only for `int`, `double` and `std::string` types.

For different types, the function should print `DataPair:  <first>, <second>`. The function should be implemented in the `/include/DataPair.hpp` file.


