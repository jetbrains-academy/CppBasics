[Move semantics](https://en.cppreference.com/w/cpp/language/move_constructor) is a feature of C++ that allows you to efficiently transfer ownership of an object from one variable to another without copying the object. This can be useful for improving performance and avoiding unnecessary memory allocations. Before diving into move semantics, let's briefly understand [value categories](https://en.cppreference.com/w/cpp/language/value_category) concept.

**lvalue** reference represents an object that has a name or an identifier. It refers to something that exists in memory and typically persists beyond a single expression. It usually stands on the left side of an assignment operator (`=`), hence the name lvalue.

**rvalue** reference represents a temporary or disposable value. It is usually the result of an expression and might not have a named memory location. Rvalues are often short-lived.

#### Move Semantics Overview
- Efficient Resource Transfer. Move semantics allows the transfer of ownership from one object to another without copying. This is especially beneficial for large or resource-intensive objects.
- [Rvalue References](https://en.cppreference.com/w/cpp/language/rvalue_reference). Move semantics utilize rvalue references (`&&`), representing temporary objects or objects about to be destroyed. Rvalue references to facilitate the efficient transfer of ownership without unnecessary overhead.
- [`std::move`](https://en.cppreference.com/w/cpp/utility/move) Function. The `std::move` function is used to convert a lvalue (an object with a name) into a rvalue reference. This is a key tool for explicitly indicating that ownership can be moved.

#### Move Semantics with `std::unique_ptr`
`std::unique_ptr` supports move semantics through its `std::move()` member function. The `std::move()` function transfers ownership of the object from the source `std::unique_ptr` to the destination unique_ptr. The source `std::unique_ptr` is then left in a null state.

Here is an example of how to use the `std::move()` function to transfer ownership of a `std::unique_ptr` object:

```cpp
#include <memory>

class MyClass {
public:
    MyClass() {
        std::cout << "MyClass Constructor\n";
    }

    ~MyClass() {
        std::cout << "MyClass Destructor\n";
    }
};

int main() {
    // Create two unique_ptr objects.
    std::unique_ptr<MyClass> p1 = std::make_unique<MyClass>();
    std::unique_ptr<MyClass> p2;

    // Transfer ownership of p1 to p2.
    p2 = std::move(p1);

    // p1 is now in a null state.
    assert(p1 == nullptr);

    // p2 now owns the MyClass object.
    assert(p2 != nullptr);

    return 0;
}
```

Move semantics can be helpful for a variety of tasks, such as passing a `std::unique_ptr` object to a function that takes ownership of the object, returning a `std::unique_ptr` object from a function and moving a `std::unique_ptr` object from one container to another.

Implement functions `transfer_ownership` and `swap_ownership` using `std::move()` function, so that the code in main function compiles and runs successfully.