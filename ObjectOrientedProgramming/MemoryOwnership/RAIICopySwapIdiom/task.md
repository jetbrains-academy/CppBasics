Concluding the presentation of the ownership model in the C++ language,
we need to discuss several related essential concepts and idioms.

[_Resource Acquisition Is Initialization_](https://en.cppreference.com/w/cpp/language/raii), 
__RAII__ for short, is a programming technique which involves linking a resource 
(such as dynamically allocated memory block, open file, network connection, _etc._)
to the lifetime of an object.
According to this idiom: 

1. the constructor of the class should allocate and initialize 
   all the resources that the object will own during its lifetime;
2. the copy constructor (and copy assignment operator) of the class 
   should copy the resource,
   if the resource is not copyable, then this constructor should be deleted; 
3. the move constructor (and move assignment operator) of the class 
   should transfer the ownership of the resource;
4. the destructor of the class should release all the resources that the object owns.

[//]: # (TODO: mention `= default` and `= delete` syntax)

[**Rule of five**](https://en.cppreference.com/w/cpp/language/rule_of_three)
is a related concept, which states that if a class requires a custom
1. destructor
2. copy constructor
3. copy assignment operator
4. move constructor
5. move assignment operator
then it actually requires all five.

[//]: # (TODO: mention rule of 3)

Let us revisit the `int_array` class to see how it fits into RAII and the rule of five 
(see complete definition of the class in the file `include/int_array.hpp`).
This class manages a resource — a dynamically allocated array of integers.
The lifecycle of this array is bound to the lifetime of the `int_array` object.

The default constructor creates an empty array:

```c++
int_array()
    : data_(nullptr)
    , size_(0)
{};
```

Another way to look at the default constructor 
is as if it creates an array in special "empty" state — 
this point of view will become handy later.

Another constructor of the class creates an array of the given size
by actually allocating the memory for it:

```c++
explicit int_array(std::size_t size)
    : data_(new int[size])
    , size_(size)
{};
```

As such, the destructor has to deallocate this memory:

```c++
~int_array() {
    delete[] data_;
}
```

<div class=hint">
    Note that we do not check for the null pointer,
    as deleting `nullptr` is a safe operation that has no effect.
</div>

Now, the rule of five dictates that the class should also define
custom copy constructor, move constructor, as well as copy and move assignment operators.
We have already seen both of these in the previous lessons:

```c++
int_array(const int_array& other)
        : data_(new int[other.size_])
        , size_(other.size_)
    {
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    };

int_array(int_array&& other)
    : data_(other.data_)
    , size_(other.size_)
{
    other.data_ = nullptr;
    other.size_ = 0;
};
```

Notice how the move constructor resets the argument object into an "empty" state.
Calling the destructor on this "empty" object later will effectively have no effect.
Validly so, as the ownership of the resource has been transferred to the new object.

Next, we need to define the assignment operators.
To avoid code duplication between copy constructor and copy assignment operator
(and similarly between move constructor and move assignment operator)
it is possible to use another clever trick called 
the [__Copy-and-Swap idiom__](https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Copy-and-swap). 

With the help of this idiom, it is sufficient to define
just a single version of assignment operator, 
which should take the argument by value:

```c++
int_array& operator=(int_array other) {
    swap(other);
    return *this;
}
```

Depending on whether the operator is called with 
an lvalue (taken as `const int_array&`) or rvalue (taken as `int_array&&`)
as an argument, the copy constructor or move constructor 
will create a local copy (`int_array`) of the data in the `other` variable.
Then, with the help of the swap function (see definition below), 
the assignment operator swaps the data of the current object with the data of the local copy.
The temporary local copy then destructs, releasing the old data along the way.

The `swap` function performs an exchange of the data between two objects,
with the help of the standard function `std::swap` capable of swapping the variables of primitive types:

```c++
void swap(int_array& other) {
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
}
```

This way, the `int_array` class implements the _RAII_ principle,
following the _rule of five_ and the _copy-and-swap_ idiom.

In conclusion, you might have a look at the implementation of other methods of 
the `int_array` class in the `include/int_array.hpp` file.
In particular, you might find interesting:

```c++
int& operator[](std::size_t i);
const int& operator[](std::size_t i) const;
```

* the two versions of custom array subscript operator `operator[]` 
  for a mutable and constant `int_array` object;

```c++
std::ostream& operator<<(std::ostream &os, const int_array& array)
```

* the printing operator `operator<<`.