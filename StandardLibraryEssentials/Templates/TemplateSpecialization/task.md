Sometimes you will need to handle different types of template parameters differently. 

For example, you may want to create a function that works with any type, but if the type is a pointer, you want to follow an alternative way. Fortunately, you can use template specialization to create a special version of the function for pointers, as well as for any other type. To do so, you need to write a function implementation with a defined type, like this:
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

When the compiler sees any call of a template function, it will first check if there is a specialized version of the function for the type of the argument. If there is, it will use the specialized version, otherwise it will use the general version.

There is a technique called metaprogramming that allows you to write code that generates code. This is done by using templates and template specialization. Since it is a complex topic, we will not cover it in this course, but you can find more information about it in the [C++ documentation](https://en.cppreference.com/w/cpp/meta). But there is a feature called type traits that can be useful in some cases. Type traits are a set of classes that provide information about types at compile time. You can use them to check if a type has a specific property, like being a pointer or a reference. You can find more information about type traits in the [C++ documentation](https://en.cppreference.com/w/cpp/header/type_traits).

Since each specialization requires a separate implementation, it is not always the best solution. In many cases, you can try to find any common type property and use it's checker, like the `std::is_pointer` function to check if the type is a pointer and handle it in the general function. This way, you can avoid code duplication and make the code more readable.
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
In this case, the function takes the first argument and then calls itself recursively with the rest of the arguments. The recursion stops when there are no more arguments left. Note that there should be a base case for the recursion, which is the first function in this example; otherwise, the compiler will generate an error.

Your task would be to create a template function for printing information about `DataPair` objects, that you've implemented in the previous task. The function should take a `DataPair` object and print the values of its fields. If the type of the field is a pointer, it should print the value of the pointer, otherwise it should print the value itself. 

Moreover, if two fields are of the same type, the function should print the `<Typename> DataPair:  <first>, <second>` string, where `<Typename>` is the name of the common type. Since the class name is not a part of the standard C++ library, let's specify it only for `int`, `double` and `std::string` types.

For different types, it should print `DataPair:  <first>, <second>`. The function should be implemented in the `/include/DataPair.hpp` file.


