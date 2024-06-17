Imagine that you have a function for calculating the sum of two numbers. If you want to calculate the sum of two integers, you can write a function that takes two `int` numbers as arguments and returns their sum. However, suppose you also want to have such a function for `double`, `long long`, `float`, or some custom data type. You will have to write a separate function for each type. This becomes inconvenient, as you end up writing multiple functions that essentially do the same thing but with different data types.

Templates are designed to address this exact issue. They allow you to write a single function that works with multiple types. For instance, you can write a template function that takes two arguments of any type and returns their sum as a variable of the same type.

The syntax for creating a template function is simple: you start with the `template` keyword, followed by the `typename` keyword, and then include the type name you want to use as a template parameter. Then, you can use this type name in the function as if it was a regular type:

```cpp
template <typename T>
T sum(T a, T b) {
    return a + b;
}
```

The number of template parameters is not limited to one. If you need to use multiple types for the function arguments, you can apply several template parameters. Here is an example function featuring two:
```cpp
template <typename T1, typename T2>
T1 sum(T1 a, T2 b) {
    return a + b;
}
```
This function will work with any pair of types, as long as the first type supports the `+` operator and the second type can be cast to the first. Note that the return type of the function is `T1`, so the result of the sum will be of the same type as the first argument.

Templates can also be used with classes. You can create a class template to work with different types. The syntax is similar to the function template, but you need to specify the template parameters before the class name:
```cpp
template <typename T, typename U>
class Person {
public:
    T age;
    U name;
    Person(T age, U name) : age(age), name(name) {}
};

int main() {
    Person<int, std::string> p1(25, "John");
    char name[10] = "Bob";
    Person<double, char*> p2(25.5, name);
    return 0;
}
```

Template instantiation is the process through which the compiler creates a "concrete" function or class from a template, using a specific type. When you use a template with a particular type, the compiler generates an instance of the template for that type. This is known as an "instantiated" function or class. For example, let's get back to the sum function template:
```cpp
template <typename T>
T sum(T a, T b) {
    return a + b;
}

int main() {
    int result = sum<int>(2, 3);
}
```
When we call `sum<int>(2, 3)`, the compiler generates a function
```cpp
int sum(int a, int b) {
    return a + b;
}
```
and uses it to calculate the sum of two integers.

The same process applies to class templates. The key point is that a separate function or class is generated for each type with which a template is used. This is why templates are a compile-time feature.

<div class="hint">
    Sometimes, you may face a template declaration using the `class` keyword instead of `typename`. Both keywords are interchangeable in template declarations, and in most cases, you can use either. However, there are a few exceptions. For more information, refer to this article: https://mariusbancila.ro/blog/2021/03/15/typename-or-class/.
</div>

If the number of parameters is unknown, you can use variadic templates. This allows you to create a function that can take any number of arguments of any type. Here is the syntax:
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

In this task, you need to implement an analog of the [`std::pair`](https://en.cppreference.com/w/cpp/utility/pair) class. In essence, it should be a class with two template parameters, `T1` and `T2`, and two fields of these types, to store two values simultaneously.
Go to the `/include/DataPair.hpp` file and create the `DataPair` class template there. The class should have the following methods:
- A no-argument constructor that initializes the fields with default values (assuming the types `T1` and `T2` have their own default constructor).
- A constructor that initializes the fields with the given argument values.
- `getFirst` and `getSecond` methods that return the values of the corresponding fields.
- `setFirst` and `setSecond` methods that set the values of the corresponding fields.

Outside the class, implement a `makePair` function that creates an instance of the `DataPair` class with the given argument values.
