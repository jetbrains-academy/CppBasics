Now let us apply the newly acquired knowledge
to extend the mechanics of our game by adding a new kind of game objects —
enemy objects visualized as black holes.
As you will see, with the help of object-oriented programming tricks,
this task can be accomplished quite easily.

The enemy object should behave as follows:
- it should move on a scene in a random direction, changing it periodically;
- it should consume star objects upon collision;
- star objects should change their status to `WARNED` when
  the enemy object is approaching them
  (similar to how they behave when the player object approaches);
- when the enemy object collides with the player object, the latter
  should change its status to `DESTROYED`, becoming effectively immovable.

Let us proceed to the implementation of this behavior.
First, take a look at the declaration of the `EnemyObject` class.
As it inherits from the `CircleGameObject` class,
a corresponding circular shape and behavior are already attached to it.
Moreover, the `getKind()` method of the `EnemyObject` class
distinguishes enemy objects from other kinds of objects (player and consumable)
by returning the `GameObjectKind::ENEMY` value.

We have already partly implemented the movement behavior of the `EnemyObject` for you.
To do so, we have added two new fields to the objects of this class:
- the `velocity` field is a vector storing the direction and speed of the object's current velocity;
- the `updateTimer` field stores the time elapsed since the last update of the object's velocity.

The `getVelocity()` method simply returns the value of the `velocity` field.
The `update(sf::Time delta)` method is responsible for periodically updating the object's velocity.
It takes as an argument the amount of time elapsed since the last update.
The implementation simply checks if the overall amount of elapsed time
is greater than the predefined time period (1 second),
and if so, it resets the velocity to a new randomly generated one
by calling the `updateVelocity()` method.
Your task is to implement this method. 

The method should generate a random direction vector, multiply it by the speed scalar constant, 
and assign the result to the `velocity` field. 
That is, the following formula should be used:
```
v` = S * d
```
where:
* `` v` `` is the new velocity vector,
* `S` is the speed constant `SPEED`,
* `d` is a direction vector.

You have the freedom to define a direction vector as you like,
but it should satisfy the following constraints:
* the `x` and `y` coordinates should either be equal to `1`, `0`, or `-1`, and
* the vector should be randomly generated: several consecutive invocations of a method
  should not likely result in the same direction being generated.

To generate a random direction vector, you might find the following functions useful:

```c++
bool    generateBool(float prob = 0.5f);
int     generateInt(int min, int max);
float   generateFloat(float min, float max);
Point2D generatePoint(const Rectangle& boundingBox);
```

A detailed description of these functions can be found in the documentation 
alongside their definitions in the `utils.hpp` file.

Moving forward with the `Enemy` class, 
the easy part is to implement the `getTexture` method.
It should return a new special texture for the enemy objects.
This texture has a corresponding id — `GameTextureID::BLACKHOLE`.

The harder part is to implement the collision behavior.
When an enemy object collides with the player object, the player object should become inactive.
This can be achieved by setting the status of the player object to `DESTROYED`.
However, an enemy object does not have direct access to the `setStatus` method of the player object.
To implement the desired behavior, you actually need to
modify the `onCollision` method of the `PlayerObject` class, not the `EnemyObject` class!

<div class="hint">

In the implementation of the `PlayerObject::onCollision` method,
remember to check that the collision occurred with an enemy object,
not an object of some other kind!

</div>

Notice that from the perspective of the consumable objects,
both the player and the enemy objects behave similarly,
so you do not need to modify their behavior. 