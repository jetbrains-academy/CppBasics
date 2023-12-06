Let us now consider another essential class of the game — the `Scene` class.
Game scene object is responsible for handling user input, 
keeping the game objects and managing their updates,
drawing the graphics on the window, and other activities.
In essence, it is a working horse of our simple game engine.

Let us have a look at the declaration of the `Scene` class.
This class is pretty packed — it includes both regular and virtual methods
as well as some data fields.
For the details on the meaning of these methods, we refer to their documentation.

The `Scene` class groups its members into three sections: `public`, `protected`, and `private`.
Let us finally decipher their meaning!

With the help of these _visibility modifiers_,
the class can govern how its clients interact with the objects of this class:

* all the fields and methods declared inside `public` section 
  are visible and can be used freely outside the class;
* all the fields and methods declared inside `protected` section
  are visible and can be used in the class itself and inside its ancestors;
* all the fields and methods declared inside `private` section
  are visible and can be used only in the class itself, and in no other place;
* there is a single exception to the previous rule — 
  a class marked as a `friend` of a given class can access its protected and private members.

The publicly available fields and methods of the class are also called its _public interface_
(not to be confused with the term _interface_ denoting classes containing pure virtual functions and having no state).
The public interface of a class defines how the objects of this class are visible from the outside,
what fields and methods can the clients of the class access.

[//]: # (TODO: add a note about visibility-inheritance modifier)

You might be wondering what is the point of hiding some fields or methods of the class — 
after all, they can be useful outside.
However, the ability to hide some of the object's _implementation details_
gains the objects an ultimate control over their internal state.

This principle is known under the name _encapsulation_.
Encapsulation allows the developer of a class to maintain the _invariants_ on object's data,
ensuring that objects of this class always remain in some valid state.

Let us explain this on the example of the `Scene` class.
Among other things, this class is responsible for storing the game objects appearing on the scene.
One useful invariant that `Scene` class may enforce is that all of its game objects are lay within the scene's borders.
But if the `GameObject` class provides a `public` method to change object's position (i.e. `setPosition`),
then the `Scene` object has no means to guarantee this property.
Any other class or function may change the position of an object and put it outside the visible area of the scene.
However, if the only way for a user class to change position of an object is through a call
to a scene's method (for example, its `move` method) — then the implementation of this method may
take some additional actions in order to guarantee that the object remains within the scene. 
This way, by controlling the visibility of objects' fields and methods,
the developer of a class may enforce various useful invariants on the state of a program.

Mastering the invariants of classes and controlling the visibility of their members is 
a skill that comes with the experience. The more complex applications you will architect and develop, 
the better you will become at designing classes and their invariants.  

To consolidate the material of this step, please 
implement the following two methods of the `Scene` class.

```c++
void setObjectPosition(GameObject& object, Point2D position);
void move(GameObject& object, Point2D vector);
```

You need to guarantee the invariant of the `Scene` class we discussed above —
the objects of the scene should remain within its borders.

To implement these methods, you have to use 
corresponding methods of the `GameObject` class, 
as well as another method the `Scene` class — the `fitInto` method.
This method adjusts the position of an object to fit into the `Scene` borders.

<div class="hint">

Note that `Scene` class is declared as a `friend` of `GameObject` class
(see the class declaration in the `gobject.hpp` file).
Thus, the `Scene` class can access `setPosition` method of the `GameObject` class, 
even though it is declared as a private method.

</div>
