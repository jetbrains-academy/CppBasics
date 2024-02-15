Let us finally dive into the object-oriented programming paradigm.

At its core lies the concept of an _object_.
An object groups together some data, called the object's _state_,
with a set of functions operating on this data.
These functions are also called the _methods_ of the object.
In this way, objects are similar to structures, but unlike plain structures,
they also allow the addition of functions into their definition.

Objects are grouped into _classes_.
A class defines a blueprint from which objects are created.
In other words, a _class_ is just a type of objects.

For example, let us consider the `GameObject` class.
The objects of this class represent entities appearing on the game scene,
such as the planet object controlled by the player,
consumable star objects, and others that we will add later.
Instances of this class will store data related to a game object,
such as its position on the scene, and some methods to manipulate the object.

Let us have a look at the `GameObject` class definition.
First, note that in C++, a new class is defined with the help of the `class` keyword.
Next comes the keyword `public` — we will describe its meaning in the later steps.
After that come the methods of the class.
There are plenty of these, and you can get the meaning of each method
by consulting its _documentation_, given as a docstring comment in front of the method declaration.

<div class="hint">

A docstring is a specially formated comment used to document a specific segment of code.
This format is widely used in C/C++ libraries and frameworks to document their API.  
Dedicated tools like [Doxygen](https://www.doxygen.nl/index.html) 
can scan the source code of your program and extract these docstring comments 
to produce documentation in various formats, such as HTML or PDF.

The docstring format supports various annotations used to document 
specific aspects of a given code block. 
For example, the `@param` annotation can be used to document the arguments of a function, 
the `@return` annotation can be used to document the return value of a function, etc.
You can learn more about the docstring format by consulting 
the dedicated [page](https://www.doxygen.nl/manual/docblocks.html).

</div>

The `GameObject` class itself does not define any data fields, only methods.
It, however, implicitly defines a bunch of _properties_ of an object, for example, its position.
A property's value can be requested using its _getter_ method (e.g., `getPosition`),
and it can be changed using its _setter_ method (e.g., `setPosition`).
Note that some object properties have both _getter_ and _setter_ methods,
like the aforementioned `getPosition` and `setPosition` methods,
while others have only a _getter_, for example, `getVelocity`.
There's a reason for this — some properties are derivatives of the objects' current status
and they cannot be directly changed from the outside.

Another piece of unfamiliar syntax here is the `const` keyword coming after the arguments of a method.
It denotes _constant methods_ — those methods that cannot change the state of the object.

Finally, the `virtual` keyword denotes _virtual_ methods — these are methods
that can be _overridden_ by inheritors of the class
(we will delve back into inheritance in the next task).
The `= 0` syntax at the end of the virtual method indicates that
it is a _pure virtual_ method.
Such a method is not implemented for the given class —
it is just a stub for an actual method implementation.

Classes that do not declare any data fields and contain pure virtual methods are also called _interfaces_.
In some sense, interfaces just provide a description of the objects' behavior,
without actually specifying their internal status.
This leaves a programmer an opportunity to define several _subclasses_
of an interface that provide different implementations of its behavior.
For example, in the following steps of this lesson, you will need to implement
subclasses for playable objects, consumable objects, and others.

Before moving to the following step, please complete a small programming exercise.
One of the methods of the `GameObject` class — the `move` method — is actually not `virtual`.
This is because it can be implemented using other methods of this class, namely `getPosition` and `setObjectPosition`.
For the programming assignment, please provide an implementation of this method.

The implementation of the method should be put into the `gobject.cpp` file.
Note that the methods' definitions given in this file contains both
the name of the class and the name of the method, separated by `::`.

```c++
void GameObject::move(Point2D vector) {
    ...
}
```
