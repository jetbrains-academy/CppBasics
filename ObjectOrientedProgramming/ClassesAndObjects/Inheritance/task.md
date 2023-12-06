As we have mentioned, `GameObject` class on itself
does not specify the state of game objects — it just describes their behavior.
We need another class that extends `GameObject` with an actual state.

Fortunately, object-oriented programming has a suitable concept for this job —
it is called class _inheritance_.
Inheritance mechanism allows extending an existing class
and providing concrete implementations for its virtual functions.
A _derived_ class, also called a _subclass_,
inherits all the method and fields of the _base_ class,
and can add its own new methods and fields.

[//]: # (TODO: also mention term `subtyping`)

Giving back to our problem, let us define
a `CircleGameObject` subclass of `GameObject` class.
Instances of `CircleGameObject` class represent
game objects of circular shape — like the planet object controlled by the player.

Have a look at the `CircleGameObject` class definition.
The semicolon syntax:

```
class CircleGameObject : public GameObject
```

indicates that `CircleGameObject` is a subclass of `GameObject`.

For a time being let us again ignore the `public` and `private` keywords
used in the `CircleGameObject` class.

Instead, let us note that `CircleGameObject` declares not only methods, but also two fields:
* `circle` field stores its shape data;
* `status` field stores its current status.

The very first method of the `CircleGameObject` is a special method called the _constructor_.
Constructor methods have the same name as the class itself,
and it takes single argument `circle`: `CircleGameObject(Circle circle)`.
The constructor is called to create an instance of an object and initialize its state.
For now, you can omit the `explicit` keyword put at the constructor --- we will get back to it later.

[//]: # (TODO: explain explicit constructors)

The definition of the `CircleGameObject` constructor body contains some new interesting syntax:

```c++
CircleGameObject::CircleGameObject(Circle circle)
    : circle(circle)
    , status(GameObjectStatus::NORMAL)
{}
```

After the arguments' list comes the semicolon `:`, followed by the list of the object's fields.
The value, provided in the brackets next to the field's name, is used to initialize the corresponding field.
Please note that the order of the fields in the _constructor initializer list_ is important.
It should match the order in which the fields are declared in the class.
After the constructor initializer list comes the constructor body `{}` (empty in this case).
Similarly, as regular methods, it can contain arbitrary C++ statements.

A constructor has its counterpart — the _destructor_ method,
which should have the same name as a class prefixed with `~`.
It is a method called automatically before destruction of the object to perform some clean-up routines.
A class can have several constructors taking different arguments,
but there could only one destructor taking no arguments.

In fact, you may have already seen the destructor on the previous step:
a class `GameObject` has a virtual destructor `~GameObject()`.
The `= default` syntax at the end of its definition indicates that
this destructor has default auto-generated implementation.

As we will see later in the course, constructors and destructors have a pivotal role in C++.

Going back to the `CircleGameObject` class, consider its methods.
Some of them, like `getPosition` and `setPosition`, are just re-declared methods of the `GameObject` class.
The keyword `override` at the end of the methods' declarations indicates this fact.

However, unlike the `GameObject` class, the `CircleGameObject` class can actually define the behavior of these methods.
To be precise, it is your task to implement some of them,
namely `getPosition`, `setPosition`, `getStatus`, `setStatus`, and `getCircle`.

<div class="hint">

Note that the position of the `CircleGameObject` is a position of its circle's center.

</div>

