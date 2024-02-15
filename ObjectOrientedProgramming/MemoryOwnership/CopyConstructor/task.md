 In C++, a class can define a special kind of constructor,
 called the _copy constructor_.
 
For example, consider the `int_array` class, which represents 
a dynamically allocated array of integers
(see the complete definition of the class in the file `include/int_array.hpp`):

This class has two fields: a pointer to the allocated array and its size.
It also defines the default constructor creating an empty array, 
and one custom constructor creating a new array of the given size.
The destructor of the class deallocates the array.

<div class="hint">
    Note that we do not check for the null pointer in the destructor,
    as deleting a `nullptr` is a safe operation that has no effect.
</div>

To effectively work with an array, the class also 
defines a `size()` method to query for the size of the array,
overloads the array subscript operators to provide access to the underlying array,
and overloads the printing operator to display the contents of the array. 

<div class="hint">

Note that there are two overloads of array subscript operator:
one for a mutable array and one for an immutable array. 

</div>

Now, suppose a user of this class has created an array:

```c++
int_array a = int_array(10);
for (size_t i = 0; i < a.size(); ++i) {
    a[i] = (int) i + 1;
}
```

They might want to create a copy of this array.
Of course, one can do that manually by creating an array of a suitable size
and assigning elements in a loop.

However, C++ provides a more convenient way to do this,
by defining a special _copy constructor_:

```c++
int_array(const int_array& other)
    : data_(new int[other.size_])
    , size_(other.size_)
{   
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
};
```

Now, the user of the class can create a copy as simply as follows: 

```c++
int_array b(a);
```

Another possible use-case scenario: given two existing arrays, 
a user might want to reassign one of them, copying the elements of the other.
The C++ language has a tool for that too!
It is called the _copy assignment operator_, which can be declared as follows:

```c++
int_array& operator=(const int_array& other) {
    if (this == &other) {
        return *this;
    }
    delete[] data_;
    data_ = new int[other.size_];
    size_ = other.size_;
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
    return *this;
}
```

<div class="hint">

The first `if` statement in the implementation of the operator
handles the case of self-assignment — in this case, the method simply returns.

</div>

<div class="hint">

Note that the assignment operator returns a reference `int_array&` 
to the object itself as a result.
It is required to support multiple assignments syntax, 
_e.g._: 

```c++
a = b = c;
```

</div>

The copy assignment operator can be used as follows:

```c++
int_array c = int_array(4);
for (size_t i = 0; i < a.size(); ++i) {
    c[i] = 0;
}
// re-assign c
c = a;
```

<div class="hint">

Note that when the following syntax is used:

```c++
int_array b = a;
```

the copy constructor will be called, not the assignment operator!

</div>
