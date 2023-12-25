Despite class `CircleGameObject` adds some data fields to the `GameObject` class,
it still leaves some of `GameObject` virtual methods unimplemented.
Therefore, this class is still an _abstract class_ — it cannot be instantiated.

We need to introduce concrete subclasses implementing the behavior of base class.  
The instances of these subclasses can then be used in all places
where an instance of a base class is expected.
By substituting the concrete subclass of an object, 
we can change the behavior of the program without changing the code
of the functions which use this object!
This ability to treat objects of different classes implementing different behaviors
as objects of a common base class is known as _subtype polymorphism_.

Let us introduce two concrete subclasses of the `CircleGameObject` class —
the `PlayerObject` class and the `ConsumableObject` classes,
representing the object controlled by the player, and consumable objects respectively.
At last, both of these classes implement all the functionality required by the `GameObject` class.

Please find the declaration of these classes in the files `player.hpp` and `consumable.hpp`.
There are no new syntactic constructs here, so you should be able to understand the code in these files.

The implementations of these classes can be found in the files `player.cpp` and `consumable.cpp`.
Note that the full implementation of some methods is already provided.
For example, the `getVelocity` method of the `PlayerObject` computes
the current velocity vector by calling the `SFML` functions
to determine which keys are pressed by the player at the moment.

Your task is to implement the `getTexture` methods of both classes.
These methods should return the current texture of an object to be displayed,
depending on the current status of the object.
Although, we have not yet implemented the methods that actually update
the status of the objects, implementing the `getTexture` methods first
will give you a good opportunity to practice and learn the method call syntax.

The `getTexture` methods takes by reference one argument — object of the `TextureManager` class.
It is another predefined by us class — it is responsible for loading the textures required by the game.
A pointer to a texture can be requested by calling the `getTexture` method of the `TextureManager` class.
It takes as argument the ID of the textures — these IDs are represented by the `GameTextureID` enum.

<div class="hint">

Note that previously we used keyword `enum`, 
but the `GameTextureID` type is defined with the two keywords: `enum class`.
So what is the difference between the `enum` and `enum class` declarations?

In fact, the `enum class` (also known as a _scoped enumeration_)
is a restricted form of the regular `enum`, 
that was introduced in the C++ language to overcome 
some of its issues.

Firstly, in case of `enum class`, the names of enumeration values are kept 
withing the scope of enumeration name.
This way the enumeration values do not pollute the global scope, 
so there is no risk of accidental name clashes.

Let us see the examples. 
In case of regular `enum` the following syntax is used:  
```c++
enum Color { RED, GREEN, BLUE };
// RED, GREEN, and BLUE are globally accessible names
Color green = GREEN;
``` 
while in case of `enum class` the enumeration value can be accessed 
only though the enumeration name:
```c++
enum class Color { RED, GREEN, BLUE };
// RED, GREEN, and BLUE do not pollute global scope
Color green = Color::GREEN;
``` 

Secondly, the `enum class` does not permit implicit conversion to `int`.
For example, the following code compiles just fine:
```c++
enum Color { RED, GREEN, BLUE };
// no compilation error, variable green equals to 1.
int green = GREEN;
``` 
However, if `enum class` is used, the code will not compile:
```c++
enum class Color { RED, GREEN, BLUE };
// compilation error: no implicit conversion from Color to int.
int green = Color::GREEN;
```

</div>

Please implement the `getTexture` methods of the `PlayerObject` and `ConsumableObject`
with the following logic:
* under `NORMAL` or `WARNED` status, the player object should have `PLANET` texture;
* under `DESTROYED` status, the player object should have `PLANET_DEAD` texture;
* under `NORMAL` status, the consumable object should have `STAR` texture;
* under `WARNED` status, the consumable object should have `STAR_CONCERNED` texture;
* under `DESTROYED` status, the consumable object should not be displayed.

<div class="hint">

If you have troubles implementing the last case,
consult the documentation of the `GameObject`'s `getTexture` method.

</div>

To implement this method, you will have to call the `getTexture` method of the `TextureManager` class.
To do so use the dot syntax `.` — the same syntax as the one used to access fields of a structure:

```c++
const sf::Texture* texture = textureManaged.getTexture(id);
```