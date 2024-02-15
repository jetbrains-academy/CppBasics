As we remember, the constructor and destructor are mandatory elements of any class, 
and they are responsible for creating and destroying an object.
For any object, the period of time between its creation 
through one of its constructors and its destruction through the destructor 
is called the [_lifetime_](https://en.cppreference.com/w/cpp/language/lifetime) of this object.

The concepts of an object's lifetime and 
[_storage duration_](https://en.cppreference.com/w/cpp/language/storage_duration) 
are related, but they mean different things. 
Object lifetime refers to the object itself, while storage duration refers to the memory allocated for it. 
The storage duration is the time between the allocation of a memory region and its deallocation, 
while lifetime is the time between the construction of an object and its destruction. 
Object lifetime is equal to or less than the lifetime of its storage. 
Two objects residing in a memory region with the same storage duration can have 
different non-overlapping lifetimes.