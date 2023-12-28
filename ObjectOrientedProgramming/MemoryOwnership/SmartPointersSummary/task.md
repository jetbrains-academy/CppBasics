To summarize the differences between different types of pointers, let's take a look at the table:

| Feature                             | `T*`                          | `std::unique_ptr<T>`                    | `std::shared_ptr<T>`                             | `std::weak_ptr<T>`                                         |
|-------------------------------------|-------------------------------|-----------------------------------------|--------------------------------------------------|------------------------------------------------------------|
| **Ownership Semantics**             | Manual ownership management   | Unique ownership                        | Shared ownership                                 | Non-intrusive observer, no ownership                       |
| **Memory Management**               | Manual deallocation required  | Automatic deallocation                  | Automatic deallocation                           | No deallocation responsibility                             |
| **Copyable**                        | Copyable (shallow copy)       | Movable (transfer ownership)            | Copyable (shared ownership)                      | Copyable (shared ownership)                                |
| **Reference Counting**              | No                            | No                                      | Yes                                              | Yes                                                        |
| **Circular Dependency Resolution**  | N/A                           | N/A                                     | Resolved using weak_ptr                          | Resolved using weak_ptr                                    |
| **Use Case**                        | Low-level memory manipulation | Exclusive ownership, non-transferable   | Shared ownership, multiple references            | Observing shared ownership without affecting lifetime      |
| **Common Usage**                    | Basic pointer usage           | Scoped ownership, avoiding memory leaks | Managing shared resources, avoiding memory leaks | Breaking circular dependencies, observing shared ownership |
| **Automatic Cleanup on Scope Exit** | No                            | Yes                                     | Yes                                              | N/A (no ownership)                                         |
