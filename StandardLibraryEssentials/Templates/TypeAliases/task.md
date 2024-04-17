Type aliases are a feature in C++ that allows you to create a new name for an existing type. This can make your code more readable and easier to understand, especially when dealing with complex types such as templates or classes and functions that are deeply nested in namespaces. Type aliases can be created using either the `typedef` keyword or the `using` keyword.

The `typedef` keyword has been in C++ since its first days and is used to create a new name for an existing type. The expression looks like this: ```typedef <current_type_name> <desired_type_name>;``` Here's how you can use `typedef` to create a type alias for `long long`:
```cpp
typedef long long ll;
ll x = 1'234'567'890'987'654'321;
```

The `using` keyword was introduced in C++11 and is a more modern way to create type aliases. It is used in the same way, but the syntax is simpler and more readable than `typedef`, being ```using <desired_type_name> = <current_type_name>;``` This is how you can use `using` to create a type alias for `long long`:
```cpp
using ll = long long;
ll x = 1'234'567'890'987'654'321;
```

On top of that, `using` can be used to create type aliases for templates. This is especially useful when you want to create a type alias for a template with multiple parameters. Here's an example of how you can use `using` to create a type alias for a `std::vector` (which is an upgraded version of an array and will be covered in the next module) of `int` type:
```cpp
template <typename T>
using Arr = std::vector<T>;

Arr<int> arr = {1, 2, 3, 4, 5};
Arr<std::string> str_arr = {"hello", "world"};
```

Type aliases can also be used to create a more readable name for a complex type. For example, you can create a type alias for this complex type:
```cpp
std::pair<std::pair<int, int>, std::pair<std::string, std::string>> complex_type;

// Using type alias
using ComplexType = std::pair<std::pair<int, int>, std::pair<std::string, std::string>>;
ComplexType complex_type;
```

Note, that type aliases follow the same rules in terms of scope as regular types. They are only valid within the scope in which they are defined. This means that if you define a type alias inside a function, it will only be accessible within that function.
```cpp
long long function() {
    using ll = long long;
    ll x = 1'234'567'890'987'654'321; // This is fine
    ...
}

ll y = 1'234'567'890'987'654'321; // Error: 'll' was not declared in this scope
```

When you encounter lines like `using namespace std;` in code. It's not a type alias, but a directive that tells the compiler to extend the current scope to include all the names from the `std` namespace to your current scope. While this can save you from typing `std::` before every standard library function or object, it's considered bad practice to use `using namespace std;` in your code. This is because it can lead to naming conflicts. If you use `using namespace std;` and create function or a class with a name that is already in the `std` namespace, you will get a compilation error:
```cpp
#include <string>

using namespace std;

class string{
    const char* str;
};

int main(){
    string s; // Error: 'string' is ambiguous
    return 0;
}
```