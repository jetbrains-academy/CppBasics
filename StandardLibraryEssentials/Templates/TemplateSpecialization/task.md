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
    print(b); // also prints 5 --- the pointed-to value
    return 0;
}
```

When the compiler encounters any call to a template function, it first checks for a specialized version of the function for the argument's type. If such a version exists, it will employ it; otherwise, it will use the general version.

There is a technique called metaprogramming, which allows you to write code that generates other code using templates and template specialization. Since it is a complex topic, we will not cover it in this course, but you can find more information about it in the [C++ documentation](https://en.cppreference.com/w/cpp/meta).

Your task is to create a template function to display information about `DataPair` objects that you've implemented in the previous task. The function should take a `DataPair` object and print the values of its fields. If the field's type is a pointer, it should print the value of the pointer; otherwise, print the value directly. 

Moreover, if two fields are of the same type, the function should print the string `<Typename> DataPair:  <first>, <second>`, where `<Typename>` is the common type name. Since the class name is not a part of the standard C++ library, let's specify it only for `int`, `double`, and `std::string` types.

For different types, the function should print `DataPair:  <first>, <second>`. The function should be implemented in the `/include/DataPair.hpp` file.


