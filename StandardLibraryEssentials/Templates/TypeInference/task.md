Type inference is a powerful feature in C++ that allows the compiler to automatically deduce the type of variable or expression at compile-time. This can make your code more concise and easier to read, as well as reduce the likelihood of type-related errors. When you deal with types with huge and obscure names, type inference can make your code more readable and maintainable.

It is important to note that type inference is not the same as dynamic typing, which is a feature of languages like Python and JavaScript. In C++, a type of variable is determined once and remains unchanged until it is destroyed. 

Type inference is a compile-time feature, and the type of variable or expression is determined based on the context in which it is used. Thus, compilation time may slightly increase when using type inference, but the resulting code will be more concise and easier to read.

In C++ type inference is mainly done using the `auto` keyword, which tells the compiler to deduce the type of variable or expression based on its initializer. For example, you can use `auto` to declare a variable without specifying its type explicitly:
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

Another new keyword introduced in C++11 is `decltype`, which allows you to deduce the type of expression without actually evaluating it. This can be useful when you want to declare a variable with the same type as another expression:
```cpp
int a = 42;
decltype(a) b = 3 + a; // b is deduced to be an int
```

Sometimes, you may encounter `decltype(auto)`, which deduces the type of variable or expression using the rules of `decltype`. This can be useful when you want to preserve the reference or const-ness of the original expression. `auto` follows the template argument deduction rules and is always an object type, while `decltype(auto)` follows the `decltype` rules for deducing reference types based on value categories.
```cpp
int a = 42;
const int& ref = a;
auto b = ref; // b is deduced to be an int
decltype(auto) c = ref; // c is deduced to be a const int&
```

For both function and class templates, the compiler can often deduce the types of the template arguments from the types of the provided arguments. This means you don't always have to explicitly specify the template arguments when you call a function template. Here's how you can use template argument deduction:
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