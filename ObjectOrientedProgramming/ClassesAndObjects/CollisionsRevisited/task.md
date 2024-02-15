Now, let us restore the collision detection functionality in our refactored game.

We have already changed the signature of the collision detection function.

```c++
CollisionInfo collisionInfo(const Circle& circle1, const Circle& circle2);
```

Now, it takes two circle shapes via constant references.
Instead of a boolean flag indicating whether a collision has occurred,
it returns the `CollisionInfo` structure:

```c++
struct CollisionInfo {
    bool collide;
    float distance;
};
```

This design will give us the flexibility to compute various information
about a possible collision between two objects inside the `collisionInfo` function,
and it preserves the opportunity for other modules of our game to decide what to do with this information.
For now, we will store the boolean flag `collide`, indicating whether a collision has occurred,
and the computed `distance` between two objects. However, you
will have the opportunity to later extend this structure
with any additional information required to implement new features in our game.

You might wonder why we decided to model `CollisionInfo` as a structure,
rather than using the fancy objects we learned about in this lesson.
In fact, we did so purposefully to illustrate the following point.
Structures, declared via `struct`, and objects/classes, declared via `class`,
are not incompatible concepts in C++,
and often instances of both can be found within the same codebase.

* Objects are used to tie together data (fields) and behavior (methods).
  Objects provide _encapsulation_ and _polymorphism_.
  The state of objects can satisfy various invariants,
  maintained by carefully controlling the visibility of a class' members.

* Structures are used as simple data containers.
  They have a predictable memory layout and predictable behavior —
  there are no associated virtual methods dispatched at runtime.

In C++, structures are also sometimes referred to as [_POD types_](https://en.wikipedia.org/wiki/Passive_data_structure),
where POD stands for _plain old data_.

<div class="hint">

Technically, in C++, there is no big difference between the `class` and `struct` keywords.
For example, one can declare classes using the `struct` keyword, and vice versa.
The only real difference is that :
* in a `struct`, members have `public` visibility by default;
* in a `class`,  members have `private` visibility by default.

However, a prevalent convention among C++ developers is
to use the `class` keyword for declaring actual classes in the object-oriented programming sense,
while the `struct` keyword is used to declare POD types.

</div>

Now, with the help of the new collision detection function,
your task is to reimplement the behavior of consumable objects.
- Upon colliding with another object, the consumable should change its status to `DESTROYED`.
- When another object is approaching the consumable, it should change its status to `WARNED`.
  This should happen whenever the distance between the other object and the consumable is less than `C * r`, where
  - `r` is the radius of the consumable object,
  - `C` is a special multiplier constant.

```c++
const float CONSUMABLE_WARNED_MULTIPLIER = 6.0f;
```

To do so, please implement the `onCollision` method of the `ConsumableObject` class.
This method is periodically called from the `Scene` class, notifying the object
about potential collisions with other objects.
The function takes another object as its first argument,
and the `CollisionInfo` structure as the second,
which contains the information about the distance between the objects
and whether they actually collided.
It is up to the method's implementation to decide what to do with this information.

Note that when the consumable object becomes `WARNED`, it should eventually
change its status back to `NORMAL` once other objects have left its nearby area.
This can be achieved by also modifying the implementation of the `update` method.
This method is also periodically called from the `Scene` class to enable
the object to update its internal state.
This function takes as its single argument the amount of time elapsed since the last update,
although you will not need this information for the current task.
Reset the status of the live (that is, not `DESTROYED`!) consumable back to `NORMAL`.
If there are any objects nearby, they will be detected again during an `onCollision` call;
otherwise, the consumable object will remain in the `NORMAL` status.
