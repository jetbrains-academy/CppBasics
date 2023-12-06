Now let us restore the collision detection functionality in our refactored game.

We have already changed the signature of the collision detection function.

```c++
CollisionInfo collisionInfo(const Circle& circle1, const Circle& circle2);
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
about possible collision between two objects inside `collisionInfo` function,
and leave the opportunity to decide what to do with this information to other modules of our game.
For now, we will store the boolean flag `collide`, indicating whether the collision happened,
and the computed `distance` between two objects — but later you
will have an opportunity to extend this structure
with additional information required to implement new features in our game.

You might wonder why we decided to model `CollisionInfo` as a structure,
instead of using the fancy objects we learned in this lesson.
In fact, we did this on purpose to illustrate the following point.
Structures, declared via `struct`, and objects/classes, declared via `class`,
are not incompatible concepts in C++,
and often instances of both can be found in the same codebase.

* Objects are used to tie together data (fields) and behavior (methods).
  Objects provide _encapsulation_ and _polymorphism_.
  The state of objects can satisfy various invariants,
  maintained by carefully controlling the visibility of class' members.

* Structures are used as simple containers of data.
  They have predictable memory layout and predictable behavior —
  there are no associated virtual methods dispatched at runtime.

In C++, structures are also sometimes referred to as [_POD types_]((https://en.wikipedia.org/wiki/Passive_data_structure)),
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

Now, with the help of the new collision detection function, 
your task is to re-implement the behavior of consumable objects.
- Upon collision with another object, the consumable should change its status into `DESTROYED`.
- When another object is approaching the consumable, it should change its status into `WARNED`.
  This should happen whenever the distance between another object and consumable is less than `C * r`, where
  - `r` is the radius of the consumable object,
  - `C` is a special multiplier constant

```c++
const float CONSUMABLE_WARNED_MULTIPLIER = 6.0f;
```

To do so, please implement the `onCollision` method of `ConsumableObject` class.
This method is called periodically from the `Scene` class, notifying the object
about its potential collisions with other objects.
The function takes as a first argument another object, 
and as a second argument the `CollisionInfo` structure, 
containing the information about the distance between objects 
and whether they actually collided.
It is up to the method's implementation to decide what to do with this information.

Note that when the consumable object becomes `WARNED`, it should eventually 
change its status back to `NORMAL` when other objects left its nearby area. 
One way to achieve this is by also modifying the implementation of `update` method. 
This method is also periodically called from the `Scene` class to give 
the object an opportunity to update its internal state.
This function takes as a single argument the amount of time elapsed since the last update,
although you will not need this information in the current task.
Reset the status of the alive (that is --- not `DESTROYED`!) consumable back to `NORMAL`.
If there are some objects nearby, they will be detected again during `onCollision` call, 
otherwise the consumable object will remain in the `NORMAL` status.
