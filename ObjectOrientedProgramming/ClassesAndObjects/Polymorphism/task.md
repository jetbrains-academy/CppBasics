Despite the class `CircleGameObject` adding some data fields to the `GameObject` class,
it still leaves some of `GameObject`'s virtual methods unimplemented.
Therefore, this class is still an _abstract class_ — it cannot be instantiated.

We need to introduce concrete subclasses to implement the behavior of the base class.  
Instances of these subclasses can then be used
wherever an instance of the base class is expected.
By substituting the concrete subclass of an object, 
we can change the behavior of the program without changing the code
of the functions that use this object!
This ability to treat objects of different classes, which implement different behaviors,
as objects of a common base class is known as _subtype polymorphism_.

Let us introduce two concrete subclasses of the `CircleGameObject` class —
the `PlayerObject` class and the `ConsumableObject` class,
representing the object controlled by the player and the consumable objects, respectively.
At last, both of these classes implement all the functionality required by the `GameObject` class.

Please find the declaration of these classes in the `player.hpp` and `consumable.hpp` files.
There are no new syntactic constructs here, so you should be able to understand the code in these files.

The implementations of these classes can be found in the `player.cpp` and `consumable.cpp` files.
Note that the full implementation of some methods is already provided.
For example, the `getVelocity` method of the `PlayerObject` class computes
the current velocity vector by calling the `SFML` functions
that determine which keys are pressed by the player at the moment.

Your task is to implement the `getTexture` methods of both classes.
These methods should return the current texture of an object to be displayed,
depending on the current status of the object.
Although we have not yet implemented the methods that actually update
the status of the objects, implementing the `getTexture` methods first
will give you a good opportunity to practice and learn the method call syntax.

The `getTexture` method takes one argument by reference — an object of the `TextureManager` class.
It is another class predefined by us — it is responsible for loading game-required textures.
A texture pointer can be requested by calling the `getTexture` method of the `TextureManager` class.
It takes the ID of the textures as an argument — these IDs are represented by the `GameTextureID` enum.

<div class="hint">

Note that previously we used the keyword `enum`, 
but the `GameTextureID` type is defined with the two keywords: `enum class`.
So, what is the difference between the `enum` and `enum class` declarations?

In fact, the `enum class` (also known as a _scoped enumeration_)
is a restricted form of the regular `enum`, 
introduced in the C++ language to overcome 
some of its issues.

Firstly, in the case of `enum class`, the names of enumeration values are kept 
within the scope of the enumeration name.
This way, the enumeration values do not pollute the global scope, 
so there is no risk of accidental name clashes.

Let us see some examples. 
For a regular `enum`, the following syntax is used:  
```c++
enum Color { RED, GREEN, BLUE };
// RED, GREEN, and BLUE are globally accessible names
Color green = GREEN;
``` 
Whereas in the case of `enum class`, the enumeration value can only be accessed 
through the enumeration name:
```c++
enum class Color { RED, GREEN, BLUE };
// RED, GREEN, and BLUE do not pollute the global scope
Color green = Color::GREEN;
``` 

Secondly, `enum class` does not permit implicit conversion to `int`.
For example, the following code compiles just fine:
```c++
enum Color { RED, GREEN, BLUE };
// no compilation error, the variable green equals to 1.
int green = GREEN;
``` 
However, if `enum class` is used, the code will not compile:
```c++
enum class Color { RED, GREEN, BLUE };
// compilation error: no implicit conversion from Color to int.
int green = Color::GREEN;
```

</div>

Please implement the `getTexture` methods of `PlayerObject` and `ConsumableObject`
using the following logic:
* under `NORMAL` or `WARNED` status, the player object should have the `PLANET` texture;
* under `DESTROYED` status, the player object should have the `PLANET_DEAD` texture;
* under `NORMAL` status, the consumable object should have the `STAR` texture;
* under `WARNED` status, the consumable object should have the `STAR_CONCERNED` texture;
* under `DESTROYED` status, the consumable object should not be displayed.

<div class="hint">

If you have troubles implementing the last case,
consult the documentation of the `GameObject`'s `getTexture` method.

</div>

To implement this method, you will need to call the `getTexture` method of the `TextureManager` class.
To do so, use the dot syntax `.` — the same syntax as the one used to access fields of a structure:

```c++
const sf::Texture* texture = textureManaged.getTexture(id);
```