Type inference is a powerful feature in C++ that allows the compiler to automatically deduce the type of a variable or an expression at compile time. This can make your code more concise and easier to read, as well as reduce the likelihood of type-related errors. When dealing with types with complex and obscure names, type inference can make your code more readable and maintainable.

It is important to note that type inference is not the same as dynamic typing, a feature characteristic of languages like Python and JavaScript. In C++, a variable's type is determined once and remains unchanged until its destruction. 

Type inference is a compile-time feature where the type of a variable or expression is determined based on the context of its usage.

In C++ type inference is mainly done using the `auto` keyword, which tells the compiler to deduce the type of a variable or expression based on its initializer. For example, you can use `auto` to declare a variable without explicitly specifying its type:
```cpp
auto x = 42; // x is deduced to be an int
auto y = 3.14; // y is deduced to be a double
auto str = "Hello, World!"; // str is deduced to be a const char*
```

Sometimes, you may want to declare a reference using `auto`. In this case, you need to use `auto&` to specify that the variable is a reference:
```cpp
int a = 42;
int& ref = a;
auto b = ref; // b is deduced to be an int
auto& ref2 = ref; // ref2 is deduced to be an int&
```

Another new keyword introduced in C++11 is `decltype`, which allows you to deduce the type of the expression without actually evaluating it. This can be useful when you need to declare a variable with the same type as another expression:
```cpp
int a = 42;
decltype(a) b = 3 + a; // b is deduced to be an int
```

For both function and class templates, the compiler can often deduce the types of the template arguments from the types of the provided arguments. This means you don't always have to explicitly specify the template arguments when calling a function template, a feature called _template argument deduction_. Here's how it can be used:
```cpp
template <typename T>
void print(T value) {
    std::cout << value << std::endl; 
} 

int main() { 
    print(10); // calls print<int>(10) 
    print(3.14); // calls print<double>(3.14)
    print("Hello, World!"); // calls print<const char*>("Hello, World!") 
    return 0;
} 
```
