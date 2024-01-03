Let us now consider another essential class of the game — the `Scene` class.
The game scene object is responsible for handling user input,
keeping game objects and managing their updates,
drawing graphics on the window, and other activities.
In essence, it is the workhorse of our simple game engine.

Let us have a look at the declaration of the `Scene` class.
This class is pretty packed — it includes both regular and virtual methods
as well as some data fields.
For details regarding the purpose of these methods, we refer to their documentation.

The `Scene` class groups its members into three sections: `public`, `protected`, and `private`.
Let us finally decipher their meaning!

With the help of these _visibility modifiers_,
the class can regulate how its clients interact with the objects of this class:

* all the fields and methods declared within the `public` section
  are visible and can be freely used outside the class;
* all the fields and methods declared within the `protected` section
  are visible and can be used within the class itself and within its descendants;
* all the fields and methods declared within the `private` section
  are visible and can be used only within the class itself and nowhere else;
* there is a single exception to the previous rule —
  a class marked as a `friend` of a given class can access its protected and private members.

<div class="hint">

When applied in the context of inheritance,
as, for example, in the declaration of the `CircleGameObject`:
```
class CircleGameObject : public GameObject
```
the visibility modifiers have the following meaning:

* if a class is inherited in `public` mode, 
  the public members of the base class become public in the derived class, 
  and the protected members of the base class become protected in the derived class;
  however, private members from the base class are not directly accessible from the derived class;
* if a class is inherited in `protected` mode, 
  both the public and protected members of the base class become protected in the derived class, 
  while private members from the base class are not directly accessible from the derived class;
* if a class is inherited in `private` mode, 
  all public and protected members of the base class become private in the derived class, 
  and private members from the base class are not directly accessible from the derived class.

</div>

The publicly available fields and methods of a class are also called its _public interface_
(not to be confused with the term _interface_ denoting classes containing pure virtual functions and devoid of state).
The public interface of a class defines the visibility of the class's objects from the outside,
denoting what fields and methods the clients of the class can access.

You might be wondering why it's necessary to hide some fields or methods of a class —
after all, they could be useful externally.
However, the ability to hide certain _implementation details_
allows objects to have ultimate control over their internal state.

This principle is known under the name _encapsulation_.
Encapsulation allows the developer of a class to maintain the _invariants_ on an object's data,
ensuring that objects of this class always remain in a valid state.

Let us explain this using the example of the `Scene` class.
Among other things, this class is responsible for storing the game objects appearing on the scene.
One useful invariant that the `Scene` class might enforce is ensuring that all of its game objects lie within the scene's borders.
However, if the `GameObject` class provides a `public` method to change an object's position (i.e., `setPosition`),
then the `Scene` object has no means to guarantee this property.
Any other class or function can change the position of an object and put it outside the scene's visible area.
Conversely, if the only way for a user class to change the position of an object is through a call
to a scene's method (for example, its `move` method), then the implementation of this method can
take some additional actions to ensure that the object remains within the scene.
This way, by controlling the visibility of an object's fields and methods,
a developer can enforce various useful program state invariants.

Mastering class invariants and controlling the visibility of their members is
a skill that comes with experience. The more complex applications you architect and develop,
the more proficient you will become at designing classes and their invariants.

To consolidate the material of this step, please
implement the following two methods of the `Scene` class.

```c++
void setObjectPosition(GameObject& object, Point2D position);
void move(GameObject& object, Point2D vector);
```

You need to ensure the invariant of the `Scene` class we discussed above —
objects in the scene must remain within its borders.

To implement these methods, you must use
the corresponding methods of the `GameObject` class,
as well as another method the `Scene` class — the `fitInto` method.
This method adjusts the position of an object so that it fits within the `Scene` borders.

<div class="hint">

Note that the `Scene` class is declared as a `friend` of the `GameObject` class
(see the class declaration in the `gobject.hpp` file).
As such, the `Scene` class can access the `setPosition` method of the `GameObject` class,
even though it is declared as a private method.

</div>
