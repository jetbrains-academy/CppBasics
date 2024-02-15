As we have mentioned, the `GameObject` class itself
does not specify the state of game objects — it just describes their behavior.
We need another class to extend `GameObject` with an actual state.

Fortunately, object-oriented programming has a suitable concept for this job —
it is called class _inheritance_.
The inheritance mechanism allows extending an existing class
and providing concrete implementations for its virtual functions.
A _derived_ class, also called a _subclass_ (_subtype_),
inherits all the method and fields of the _base class_ (_base type_),
and can add its own methods and fields.

Returning to our problem, let us define
a `CircleGameObject` subclass of the `GameObject` class.
Instances of the `CircleGameObject` class represent
game objects of a circular shape — like the planet object controlled by the player.

Have a look at the `CircleGameObject` class definition.
The semicolon syntax:

```
class CircleGameObject : public GameObject
```

indicates that `CircleGameObject` is a subclass of `GameObject`.

For the time being, let us again ignore the `public` and `private` keywords
used in the `CircleGameObject` class definition.

Instead, note that `CircleGameObject` declares not only methods, but also two fields:
* the `circle` field stores its shape data;
* the `status` field stores its current status.

The very first method of the `CircleGameObject` class is a special method called a _constructor_.
Constructors have the same name as the class itself,
and, in this case, it takes a single `circle` argument: `CircleGameObject(Circle circle)`.
A constructor is called to create an instance of an object and initialize its state.

<div class="hint">

The `explicit` [specifier](https://en.cppreference.com/w/cpp/language/explicit) 
before a constructor prevents implicit type casts.
In C++, if a class has a constructor with a single argument 
that is not marked with the `explicit` keyword, 
then the compiler can automatically convert the argument type to the class type
when necessary. 

For example, if the constructor `CircleGameObject(Circle circle)` had not been 
marked as `explicit`, the following code would be able to compile:

```c++
void foo(CircleGameObject object) { /* ... */ }

int main() {
    Circle circle = { { 0.0f, 0.0f, }, 10.0f };
    // `Circle` will be implicitly converted into `CircleGameObject`
    // by calling the `CircleGameObject` constructor.
    foo(circle);
}
```

However, with the constructor marked as `explicit`, the code fragment above would not compile,
and it should be rewritten as follows:

```c++
void foo(CircleGameObject object) { /* ... */ }

int main() {
    Circle circle = { { 0.0f, 0.0f, }, 10.0f };
    CircleGameObject object(circle);
    foo(object);
}
```

In the C++ language, the use of `explicit` constructors is generally encouraged, 
as it results in more predictable behavior. 

</div>

The definition of the `CircleGameObject` constructor body contains some new interesting syntax:

```c++
CircleGameObject::CircleGameObject(Circle circle)
    : circle(circle)
    , status(GameObjectStatus::NORMAL)
{}
```

After the argument list comes the colon `:`, followed by a list of the object's fields.
The value provided in the brackets next to the field's name is used to initialize the corresponding field.
Please note that the order of the fields in the _constructor initializer list_ is important.
It should match the order in which the fields are declared in the class.
After the constructor initializer list comes the constructor body `{}` (empty in this case).
Just like regular methods, it can contain any C++ statements.

A constructor has its counterpart — the _destructor_ method,
which should have the same name as the class prefixed with `~`.
This method is automatically called before the destruction of an object to perform some clean-up routines.
A class can have several constructors with different arguments,
but there can be only one destructor, which does not take any arguments.

In fact, you may have already seen a destructor in the previous step:
the `GameObject` class has a virtual destructor `~GameObject()`.
The `= default` syntax at the end of its definition indicates that
this destructor has a default auto-generated implementation.

As we will see later in the course, constructors and destructors have a pivotal role in C++.

Going back to the `CircleGameObject` class, consider its methods.
Some of them, like `getPosition` and `setPosition`, are just redeclarations of methods from the `GameObject` class.
The keyword `override` at the end of these methods' declarations indicates this fact.

However, unlike the `GameObject` class, the `CircleGameObject` class can actually define the behavior of these methods.
To be precise, it is your task to implement some of them,
namely `getPosition`, `setPosition`, `getStatus`, `setStatus`, and `getCircle`.

<div class="hint">

Note that the position of a `CircleGameObject` corresponds to the center of its circle.

</div>

