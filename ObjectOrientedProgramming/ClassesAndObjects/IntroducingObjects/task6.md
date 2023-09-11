Now let us restore the collision detection functionality in our refactored game.

We have already refactored the collision detection function.

```c++
CollisionInfo collision(const Circle& circle1, const Circle& circle2);
```

Now it takes two circle shapes by constant references.
Instead of boolean flag indicating whether the collision occurred,
it returns the `CollisionInfo` structure:

```c++
struct CollisionInfo {
    bool collide;
    float distance;
};
```

This design will give us flexibility to compute various information
about possible collision between two objects inside `collision` function,
and leave the opportunity to decide what to do with this information to other modules of our game.
For now, we will store the boolean flag `collide`, indicating whether the collision happened,
and the computed `distance` between two objects — but later you
will have an opportunity to extend this structure
with additional information required to implement new features in our game.

You might wonder why we decided to model `CollisionInfo` as a structure,
instead of using the fancy objects we learned in this lesson.
In fact, we did this on purposes to illustrate the following point.
Structures, declared via `struct`, and objects/classes, declared via `class`,
are not incompatible concepts in C++,
and often instances of both can be found in the same codebase.

* Objects are used to tie in together data (fields) and behavior (methods).
  Objects provide _encapsulation_ and _polymorphism_.
  The state of objects can satisfy various invariants,
  maintained by carefully controlling the visibility of class' members.

* Structures are used as simple containers of data.
  They have predictable memory layout and predictable behavior —
  there are no associated virtual methods dispatched at runtime.

In C++, structures are also sometime referred
to as [_POD types_]((https://en.wikipedia.org/wiki/Passive_data_structure)),
where POD stands for _plain old data_.

<div class="hint">

Technically, in C++ there is no big difference between `class` and `struct` keywords.
For example, one can declare classes using the `struct` keyword, and vice versa.
The only real difference is that :
* in `struct` members by default have `public` visibility;
* in `class`  members by default have `private` visibility.

However, a prevalent convention among the C++ developers is
to use `class` keyword to declare actual classes in the object-oriented programming sense,
while the `struct` keyword is used to declare POD types.

</div>

[//]: # (TODO: add task)