Despite class `CircleGameObject` adds some data fields to the `GameObject` class,
it still leaves some of `GameObject` virtual methods unimplemented.
Therefore, this class is still an _abstract class_ --- it cannot be instantiated.

Let us introduce two concrete subclasses of the `CircleGameObject` class ---
the `PlayerObject` class and the `ConsumableObject` classes,
representing the object controlled by the player, and consumable objects respectively.
At last, both of these classes implement all the functionality required by the `GameObject` class.

Please find the declaration of these classes in the files `player.hpp` and `consumable.hpp`.
There are no new syntactic constructs here, so you should be able to understand the code in these files.

[//]: # (TODO: add here a paragraph about the polymorphism)

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

[//]: # (TODO: explain difference between `enum` and `enum class`)

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