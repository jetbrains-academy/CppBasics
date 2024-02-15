[Move semantics](https://en.cppreference.com/w/cpp/language/move_constructor) 
is a feature of C++ that allows to efficiently 
transfer ownership of an object without copying. 
This can be useful for improving performance 
and avoiding unnecessary memory allocations. 
Before diving into the move semantics details, let us briefly understand the concept of 
[value categories](https://en.cppreference.com/w/cpp/language/value_category).

* An __lvalue__ expression represents an object that has a name or an identifier. 
  It refers to something that exists in memory and typically persists beyond a single expression. 
  It usually stands on the left-hand side of an assignment operator (`=`), hence the name __lvalue__.

* An __rvalue__ expression represents a temporary or disposable value. 
  It is usually the intermediate result of some computation that might not have a named memory location.
  It usually stands on the right-hand side of an assignment operator (`=`), hence the name __rvalue__.

For example, below, variables `a`, `b`, and `c` are lvalues, 
while the expression `a + b` is an rvalue.

```c++
int a = 2;
int b = 3;
int c = a + b;
```

Move semantics utilize rvalues,
representing temporary objects or objects about to be destroyed.
When another object wants to copy a soon-to-be-disposed rvalue object,
instead of actual copying, the contents of the rvalue object can be moved.

For example, recall the `int_array` class, 
which has a custom copy constructor
(see file `include/int_array.hpp`):

```c++
class int_array {
public:
    /* ... */
    int_array(const int_array& other) 
        : data_(new int[other.size_])
        , size_(other.size_) 
    {
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    };
    /* ... */
private:
    int* data_;
    size_t size_;
};
```

Suppose there is a function that creates an array filled with a given value:

```c++
int_array create_array(int value, size_t size) {
    if (size == 0) {
        return int_array();
    }
    int_array array = int_array(size);
    for (size_t i = 0; i < size; ++i) {
        array[i] = value;
    }
    return array;
}
```

And then this function is called as follows:

```c++
// the copy constructor is called here (!)
int_array a = create_array(0, 4);
```

In the code above, unnecessary copying is performed,
which copies an array from an object returned from the function 
into the newly created object.

However, since the returned object is actually a temporary rvalue
that is going to be disposed of anyway, 
we can take advantage of that and instead of copying the array, 
just _move_ the pointer.

To do that, in addition to the copy constructor, 
one can define a _move constructor_, 
which takes an rvalue reference, denoted with `&&`, as an argument:

```c++
class int_array {
public:
    /* ... */
    int_array(int_array&& other) 
        : data_(other.data_)
        , size_(other.size_) 
    {
        other.data_ = nullptr;
        other.size_ = 0;
    };
    /* ... */
private:
    int* data_;
    size_t size_;
};
```

Note that in addition to copying the pointer,
the move constructor of the `int_array` class also nullifies 
the pointer in the original object passed by rvalue reference. 
It is necessary because, otherwise, once the destructor 
of the original object is called, it would deallocate the memory
pointed-to by the `data` field.
This way, the given move constructor implementation reflects 
the occurring ownership transfer.

In a similar way to the copy assignment operator, 
one can also define a move assignment operator for a class:

```c++
class int_array {
public:
    /* ... */
    int_array& operator=(int_array&& other) {
        // ...
    }
    /* ... */
private:
    int *data;
    std::size_t size;
};
```

With the help of the move assignment operator and 
the special standard function `std::move`, 
one can manually transfer ownership from one object to another:

```c++
int_array b = create_array(1, 4);
int_array c = create_array(2, 4);
// ownership transfer
b = std::move(c);
```

<div class="hint">

Technically, the `std::move` function converts an lvalue into an rvalue reference.

</div>

A custom implementation of the move assignment operator
should ensure that after being moved, 
the object remains in a valid state, 
usually some kind of null state.
This means that it should be possible to still safely destruct the object, 
but other operations such as method calls or operator 
uses might lead to undefined behavior.
In general, avoid using an object after it has been moved, 
except for assigning it a new value or destroying it.

The smart pointer `std::unique_ptr` also supports move semantics.
The move semantics of this class transfers ownership of the object
from the source `std::unique_ptr` to the destination pointer.
The source `std::unique_ptr` is then left in a null state.

```c++
std::unique_ptr<Dog> p1 = std::make_unique<Dog>("Beethoven");
std::unique_ptr<Dog> p2;
// transfer ownership from p1 to p2.
p2 = std::move(p1);
// p1 is now in a null state.
assert(p1 == nullptr);
// p2 now owns the Dog object.
assert(p2 != nullptr);
```