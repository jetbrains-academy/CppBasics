To summarize the differences between the smart pointers, let's take a look on a table:

| Feature                         | `T*` (Raw Pointer)            | `std::unique_ptr<T>`                                          | `std::shared_ptr<T>`                                          | `std::weak_ptr<T>`                                         |
|---------------------------------|-------------------------------|---------------------------------------------------------------|---------------------------------------------------------------|------------------------------------------------------------|
| Ownership Semantics             | Manual ownership management   | Unique ownership                                              | Shared ownership                                              | Non-intrusive observer, no ownership                       |
| Memory Management               | Manual deallocation required  | Automatic deallocation                                        | Automatic deallocation                                        | No deallocation responsibility                             |
| Copyability                     | Copyable (shallow copy)       | Movable (transfer ownership)                                  | Copyable (shared ownership)                                   | Copyable (shared ownership)                                |
| Reference Counting              | No                            | No                                                            | Yes                                                           | Yes                                                        |
| Circular Dependency Resolution  | N/A                           | N/A                                                           | Resolved using weak_ptr                                       | Resolved using weak_ptr                                    |
| Use Case                        | Low-level memory manipulation | Exclusive ownership, non-transferable                         | Shared ownership, multiple references                         | Observing shared ownership without affecting lifetime      |
| Common Usage                    | Basic pointer usage           | Scoped ownership, avoiding memory leaks                       | Managing shared resources, avoiding memory leaks              | Breaking circular dependencies, observing shared ownership |
| Automatic Cleanup on Scope Exit | No                            | Yes                                                           | Yes                                                           | N/A (no ownership)                                         |

#### std::auto_ptr (Deprecated):

[std::auto_ptr](https://en.cppreference.com/w/cpp/memory/auto_ptr) was a smart pointer introduced in early versions of C++ to provide a limited form of automatic memory management.
It became deprecated in C++11 and is not recommended for use in modern C++.
The reason for deprecation is its lack of proper ownership semantics. Transferring ownership using `std::auto_ptr` led to unexpected behaviors, especially when dealing with containers or other standard library components.
C++11 introduced more solid alternatives, such as `std::unique_ptr` and `std::shared_ptr`, with clearer ownership semantics and improved safety.