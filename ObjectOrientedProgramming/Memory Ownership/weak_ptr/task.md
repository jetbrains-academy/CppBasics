In C++ memory ownership, [std::weak_ptr](https://en.cppreference.com/w/cpp/memory/weak_ptr) stands out as a tool designed for managing transient ownership without affecting the object's lifetime. While `std::shared_ptr` enables shared ownership, `std::weak_ptr` complements it by providing a non-intrusive observer-like role, this pointer does not contribute to the object's reference count, allowing for the detection of object state without extending its lifetime.

#### Distinctive Features of std::weak_ptr and common usage:
- Non-Intrusive Observation. `std::weak_ptr` allows for the observation of an object without actively participating in its ownership. Unlike `std::shared_ptr`, it doesn't contribute to the reference count, and its existence doesn't affect the lifetime of the shared object.
- Breaking Circular References. In scenarios where circular dependencies among objects lead to reference cycles, using std::weak_ptr can help break the cycle. This ensures that objects are properly deallocated when they are no longer in use, even in the presence of circular references. As an example, consider a scenario where two objects, `A` and `B`, hold `std::shared_ptr` instances to each other. In this case, the reference count of each object will never reach zero, and they will never be deallocated. However, if one of the objects holds a `std::weak_ptr` to the other, the reference count will reach zero when the other object is destroyed, and the object will be deallocated.
- Locking for Access. To access the shared object, a `std::weak_ptr` must be converted to a `std::shared_ptr` using the `lock()` member function. If the shared object still exists, this operation succeeds, allowing safe access. Otherwise, it returns an empty `std::shared_ptr`.
- Observer Pattern. `std::weak_ptr` is often used in conjunction with `std::shared_ptr` to implement the observer pattern. Objects can register observers using `std::weak_ptr`, and these observers can check the object's state before attempting to access it.

Example:
```cpp

example

```