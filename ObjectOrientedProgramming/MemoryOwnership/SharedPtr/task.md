In contrast to `std::unique_ptr`, the smart pointer class  
[`std::shared_ptr`](https://en.cppreference.com/w/cpp/memory/shared_ptr) introduces 
shared ownership semantics, allowing multiple smart pointers to share control
over the same dynamically allocated object. 

Under the hood, `std::shared_ptr` implements a reference count to track 
the number of shared pointers pointing to the same object. 
The reference count is dynamically adjusted as shared pointers are created or destroyed. 
When the reference count reaches zero, the managed object is automatically destroyed.

While `std::unique_ptr` is movable but not copyable, `std::shared_ptr` is both movable and copyable. 
Copying a `std::shared_ptr` results in shared ownership.
It increments the reference counter. 
The underlying object is only deallocated when 
the last shared pointer releases its ownership.

Let us have a look at an example of `std::shared_ptr` usage: 

```c++
void test() {
    // creating a shared pointer
    std::shared_ptr<Dog> dog = std::make_shared<Dog>("Pluto");
    // using the pointer
    dog->bark();
    // creating a copy of the shared pointer
    std::shared_ptr<Dog> copy = dog;
    // both dog and copy share ownership of the same object
    std::cout << *dog << " " << *copy << "\n";
    // one can query the count of shared pointers
    // pointing to the given object 
    std::cout << "dog.use_count() = " << dog.use_count() << "\n";
    // similar to std::unique_ptr, it is possible to obtain a plain pointer
    std::cout << dog.get() << "\n";
    // when the function exits,
    // destructors of both shared pointers are called,
    // dropping the reference count to 0 and thus
    // triggering the deallocation of the pointed-to Dog object
}
```

As an exercise, let us develop a simple chat system.
It consists of two classes: `Chat` and `User` (see file `include/chat.hpp`).
Each user has a shared pointer to the chat object in which they are currently logged in.
Your task is to write the implementation of the following methods for the `User` class.

```c++
void createNewChat(std::string name);
```

* The `createNewChat` method should create a new chat with the given name 
  and log the user into it.

<div class="hint">

To create a new object pointed to by a shared pointer,
use the function `std::make_shared`

</div>  

<div class="hint">

To assign a unique identifier to the newly created `Chat` object,
use the static field `nextChatId`. 

</div>

```c++
void joinChatByInvite(const User& user);
```

* The `joinChatByInvite` method should log the user into another user's chat
  (by reassigning its chat pointer).

```c++
void leaveChat();
```

* The `leaveChat` method should log the user out of the chat.