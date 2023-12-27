In C++ memory ownership, 
[std::weak_ptr](https://en.cppreference.com/w/cpp/memory/weak_ptr) stands out as a tool 
for managing transient ownership without affecting the object's lifetime. 
While `std::shared_ptr` enables shared ownership, 
`std::weak_ptr` complements it by providing a non-intrusive observer-like role. 
This pointer does not contribute to the object's reference count, 
allowing for the detection of object state without extending its lifetime.

The main use case of `std::weak_ptr` is to break the circular reference cycles,
which can lead to memory leaks otherwise.

Going back the chat example from the previous lesson,
suppose we want to extend the `Chat` class
and add a possibility to assign a host to the chat. 

For this purpose, we might rework the `Chat` class as follows
(also see `include/chat.hpp` file):

```c++
class Chat {
public:
    Chat(int id, std::string name, const std::shared_ptr<User>& owner)
        : id(id)
        , name(std::move(name))
        , host(owner)
    {};

    /* ... */
private:
    int id;
    std::string name;
    std::shared_ptr<User> host;
};
```

Also, now, instead of `User` method `createNewChat`, 
we would declare a function with the same name:

```c++
std::shared_ptr<Chat> createNewChat(std::string name, const std::shared_ptr<User>& host);
```

This function should take the name of the chat to be created, 
as long as the shared pointer to the user who would become its host.

Now, suppose this function creates shared pointer `chat`, 
pointing to a new `Chat` object, then assigns pointer `chat->host` to `host`,
and `host->chat` to `chat`.
This would result in a reference cycle.
As long as `chat` and `host` store the shared pointers to each other,
both their reference counters cannot drop below `1`.
It means that the object will never be deallocated — 
in other words, we got the memory leak!  

In order to avoid this, we need to use `std::weak_ptr` to break the reference cycle.
In particular, the `host` field of the `Chat` object should be declared as a weak pointer.

Note that the method `getHost` of the `Chat` class should still return 
the shared pointer:

```c++
inline std::shared_ptr<User> getHost() const;
```

To achieve this, you need to use the `lock()` method of the `std::weak_ptr`.
This method creates new `std::shared_ptr` pointing to the same object 
as the given `std::weak_ptr`, if it still exists;
otherwise, it returns an empty `std::shared_ptr`.

To finish this lesson, please fix the implementation of 
the `Chat` class (see file `include/chat.hpp`)
by using `std::weak_ptr` instead of the `std::shared_ptr` for the `host` field.
Also, provide an implementation of the `createNewChat` function 
(see file `task.cpp` ).