The first kind of smart pointers in C++ we are going to look at is 
the [std::unique_ptr](https://en.cppreference.com/w/cpp/memory/unique_ptr).

This smart pointer is designed to manage the lifetime of 
dynamically allocated objects, and it provides exclusive ownership semantics.
The unique ownership model ensures that at any given time, 
only one `std::unique_ptr` instance owns a particular dynamically allocated object. 
When the owning `std::unique_ptr` is destroyed or explicitly reset, 
the pointed-to object is automatically destroyed and 
the associated memory is deallocated.

Another advantage of `std::unique_ptr` is that it helps to prevent 
memory errors, such as memory leaks and double deletion.
The `std::unique_ptr` ensures that an object will be deleted
when it is no longer needed, and that it will be deleted only once.

In addition, usage of `std::unique_ptr` improves code readability:
by making clear what pointer owns an object and is responsible for deleting it.

Let us look at the examples. 
Suppose we have a class `Dog` defined as follows.

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
    // similarly as you would do with a plain pointer
    if (!dog) {
        return;
    }
    // unique pointer can be used 
    // similarly to how plain pointers are used
    dog->bark();
    // when the function exits, 
    // the unique_ptr automatically destroys 
    // the Dog object and deallocated memory
}
```

<div class="hint">

How the automated destruction of the pointed-to object
by the `std::unique_ptr` is achieved?
In fact, the implementation of the `std::unique_ptr` class 
in the standard library simply overrides the destructor of this class. 

</div>

Alternatively, one can explicitly reset the pointer, 
and thus trigger the deletion of the pointed-to object:

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

vice versa, it is possible to take the pointer together with the ownership
out of the `std::unique_ptr` command:

```c++
std::unique_ptr<Dog> smartDog = std::make_unique<Dog>("Snoopy");
// Dog object is transferred to the plain pointer,
// it should be manually deleted eventually, 
// because the unique pointer would not do that
Dog* dog = smartDog.release();
// after release, the unique pointer is in the null state
assert(smartDog == nullptr);
```

It is possible to obtain a plain pointer without releasing the ownership. 
However, the plain pointer should not outlive the unique pointer; 
otherwise, it can result in a use-after-free error.

```c++
std::unique_ptr<Dog> smartDog = std::make_unique<Dog>("Snoopy");
// now the dog and smartDog point-to the same object;
// the ownership still belongs to the smartDog pointer
Dog* dog = smartDog.get();
```

<div class="hint">

The `get()` method is typically used to pass a unique pointer 
into a function expecting the plain pointer.
It is often the case when C++ code needs to interact with the C libraries.

</div>

Note that by converting plain pointers to unique pointers and vice versa, 
using the methods given above, you might accidentally create
two unique pointers pointing to the same object,
thus violating the ownership rules of `std::unique_ptr`.
This situation would result in undefined behavior:

```c++
std::unique_ptr<Dog> dog = std::make_unique<Dog>("Snoopy");
// the dog and anotherDog point-to the same object,
// and both incorrectly assume unique ownership of the object;
// thus both can attempt to destroy the object, 
// leading to undefined behavior.
std::unique_ptr<Dog> anotherDog(dog.get());
```

This is why you should be extremely careful when converting 
between plain and unique pointers. 
As a rule of thumb, try to complete avoid these conversions in your code.

By default, the `std::unique_ptr` attempts to prevent such misuses
and enforce the single ownership rule.
This is why, for example, the copy constructor of the `std::unique_ptr` is disabled:

```c++
std::unique_ptr<Dog> dog = std::make_unique<Dog>("Snoopy");
// compilation error
std::unique_ptr<Dog> anotherDog = dog;
```

In order to consolidate the material of this lesson,
finish the implementation of `copy` function.
This function takes as an argument an array of integers, 
given as a plain pointer and a size,
and it should return a copied array as a unique pointer.
If the given array size is `0`, 
then the function should return the null pointer. 

<div class="hint">

To create a unique pointer to an array, use the following syntax:
```c++
std::make_unique<int[]>(size)
```

</div>