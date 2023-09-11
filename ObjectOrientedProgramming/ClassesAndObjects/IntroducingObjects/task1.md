Let us finally meet with the object-oriented programming paradigm.

At the core of this paradigm lies the concept of the _object_.
An object groups together some data, called object's _state_, 
with a set of functions operating on this data.
These functions are also called the _methods_ of the object.
In this way, objects are similar to structures, but unlike plain structures, 
they also allow to add functions into their definition.

Objects are grouped into _classes_. 
Class defines a blueprint after which the objects are created.
In other words, a _class_ is just a type of objects.

For example, let us consider the `GameObject` class. 
The objects of this class represent entities appearing on the game scene, 
such as the planet object controlled by the player, 
consumable star objects, and others that we will add later.
Instances of this class will store data related to a game object,
such as its position on the scene, and some methods to manipulate the object.

Let us have a look at the `GameObject` class definition.
First note that in C++ new class is defined with the help of the `class` keyword.
Next comes the keyword `public` --- we will describe its meaning in the later steps.
After that come the methods of the class.
There are plenty of them, you can get the meaning of each method
by consulting its _documentation_ given as a docstring comment in front of the method declaration.

[//]: # (TODO: add links to docstring format)

The `GameObject` class itself does not define any data fields, only the methods.
It, however, implicitly defines a bunch of _properties_ of an object, for example, its position.
A value of a property can be requested using its _getter_ method (e.g. `getPosition`),
and it can be changed using its _setter_ method (e.g. `setPosition`).
Note that some properties of an object have both _getter_ and _setter_ methods,
like aforementioned `getPosition` and `setPosition` methods,
while others have only _getter_, for example `getVelocity`.
This is for a reason — some properties are derivatives of the current objects' status, 
and they cannot be directly changed from the outside. 

Another piece of unfamiliar syntax here is the `const` keyword coming after the arguments of a methods. 
It denotes the _constant methods_ --- these methods cannot change the status of the object.

Finally, keyword `virtual` denotes the _virtual_ methods — these are the methods
that can be _overridden_ by the inheritors of the class 
(we will delve back to inheritance in the next task).
The `= 0` syntax at the end of the virtual method indicates that 
it is a _pure virtual_ method.
Such a method is not implemented for the given class — 
it is just a stub for an actual method implementation.

The classes that do declare any data fields and contain pure virtual methods are also called _interfaces_.
In some sense, interfaces just provide a description of the objects' behavior,
without actually specifying their internal status.
These leaves a programmer an opportunity to define several _subclasses_
of an interface that provide different implementations of its behavior.
For example, in the following steps of this lesson, you will have to implement 
a subclass of playable objects, consumable objects, and others.

But before moving to the following step, please complete a small programming exercise.
One of the methods of the `GameObject` class --- the `move` method --- is actually not `virtual`.
It is because it can be implemented in terms of other methods of this class, namely `getPosition` and `setObjectPosition`.
To finish the programming assignment, please provide an implementation of this method.

The implementation of the method should be put into `gobject.cpp` file.
Note that methods' definition given in this file contains both 
name of the class, and the name of the method, separated by the `::`.

```c++
void GameObject::move(Point2D vector) {
    ...
}
```
