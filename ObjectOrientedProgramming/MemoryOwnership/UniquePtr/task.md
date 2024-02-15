The first kind of smart pointers in C++ we are going to look at is 
[std::unique_ptr](https://en.cppreference.com/w/cpp/memory/unique_ptr).

This smart pointer is designed to manage the lifetime of 
dynamically allocated objects and provides exclusive ownership semantics.
The unique ownership model ensures that at any given time, 
only one `std::unique_ptr` instance owns a particular dynamically allocated object. 
When the owning `std::unique_ptr` is destroyed or explicitly reset, 
the pointed-to object is automatically destroyed and 
the associated memory is deallocated.

Another advantage of `std::unique_ptr` is that it helps to prevent 
memory errors, such as memory leaks and double deletions.
The `std::unique_ptr` ensures that an object will be deleted
when it is no longer needed and that it will be deleted only once.

In addition, the usage of `std::unique_ptr` improves code readability
by making clear which pointer owns an object and is responsible for deleting it.

Let us look at some examples. 
Suppose we have a class `Dog` defined as follows:

```c++
class Dog {
public:
    explicit Dog(const std::string& name) : name(name) {}
    ~Dog() {}

    std::string bark() const {
        std::cout << "Woof!\n";
    }
private:
    std::string name;
};
```

The following code snippet demonstrates how to create a new `Dog` object owned by a `unique_ptr`:

```c++
void makeBark() {
    // creating a unique pointer
    std::unique_ptr<Dog> dog = std::make_unique<Dog>("Snoopy");
    // you can test if the unique pointer is a null pointer,
    // similar to how you would do with a plain pointer
    if (!dog) {
        return;
    }
    // unique pointer can be used 
    // similar to how plain pointers are used
    dog->bark();
    // when the function exits, 
    // the unique_ptr automatically destroys 
    // the Dog object and deallocated the memory
}
```

<div class="hint">

How is automated destruction of the pointed-to object
by the `std::unique_ptr` achieved?
In fact, the standard library's implementation of the `std::unique_ptr` class 
simply overrides the destructor of this class. 

</div>

Alternatively, one can explicitly reset the pointer, 
thus triggering the deletion of the pointed-to object:

```c++
std::unique_ptr<Dog> dog = std::make_unique<Dog>("Snoopy");
dog->bark();
// at this point, the pointer will be reset to null,
// and the pointed-to object will be destroyed
dog.reset();
assert(dog == nullptr);
}
```

It is also possible to transfer an existing plain pointer 
to a new `std::unique_ptr`:

```c++
Dog* dog = new Dog("Snoopy");
// ownership of the Dog object is taken by the unique_ptr,
// it should not be manually deleted, 
// as the unique pointer itself will do that 
std::unique_ptr smartDog(dog);
```

Conversely, it is possible to remove the pointer together with its ownership
from the `std::unique_ptr` command:

```c++
std::unique_ptr<Dog> smartDog = std::make_unique<Dog>("Snoopy");
// the Dog object is transferred to the plain pointer,
// it should be manually deleted eventually 
// because the unique pointer would not do that
Dog* dog = smartDog.release();
// after release, the unique pointer is in the null state
assert(smartDog == nullptr);
```

It is possible to obtain a plain pointer without releasing ownership. 
However, the plain pointer should not outlive the unique pointer; 
otherwise, it can result in a use-after-free error.

```c++
std::unique_ptr<Dog> smartDog = std::make_unique<Dog>("Snoopy");
// now the dog and smartDog point to the same object;
// ownership still belongs to the smartDog pointer
Dog* dog = smartDog.get();
```

<div class="hint">

The `get()` method is typically used to pass a unique pointer 
to a function expecting a plain pointer.
This is often the case when C++ code needs to interact with C libraries.

</div>

Note that by converting plain pointers to unique pointers and vice versa, 
using the methods given above, you might accidentally create
two unique pointers pointing to the same object,
thus violating the ownership rules of `std::unique_ptr`.
This would result in undefined behavior:

```c++
std::unique_ptr<Dog> dog = std::make_unique<Dog>("Snoopy");
// the dog and anotherDog point to the same object,
// and both incorrectly assume unique ownership of the object;
// thus both can attempt to destroy the object, 
// leading to undefined behavior.
std::unique_ptr<Dog> anotherDog(dog.get());
```

This is why you should be extremely careful when converting 
between plain and unique pointers. 
As a rule of thumb, try to completely avoid these conversions in your code.

By default, `std::unique_ptr` attempts to prevent such misuses
and enforce the single ownership rule.
This is why, for example, the copy constructor of `std::unique_ptr` is disabled:

```c++
std::unique_ptr<Dog> dog = std::make_unique<Dog>("Snoopy");
// compilation error
std::unique_ptr<Dog> anotherDog = dog;
```

In order to consolidate the material of this lesson,
complete the implementation of the `copy` function.
This function takes an array of integers as an argument, 
given as a plain pointer and its size,
and should return a copied array as a unique pointer.
If the given array size is `0`, 
then the function should return a null pointer. 

<div class="hint">

To create a unique pointer to an array, use the following syntax:
```c++
std::make_unique<int[]>(size)
```

</div>