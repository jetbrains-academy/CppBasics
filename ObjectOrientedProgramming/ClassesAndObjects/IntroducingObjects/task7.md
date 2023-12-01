Now let us apply the newly acquired knowledge 
to extend the mechanics of our game by adding a new kind of game objects — 
enemy objects visualized as black holes.
As you will see, with the help of object-oriented programming tricks, 
this task can be accomplished quite easily.

The enemy object should behave as follows:
- it should move on a scene in a random direction, changing it periodically; 
- it should consume the star objects when colliding with them;
- star objects should change their status into `WARNED` when 
  the enemy object is approaching them 
  (similarly as they do when the player object is approaching);
- when the enemy object collides with the player object, the latter 
  should change its status into `DESTROYED`, becoming effectively immovable.

Let us proceed to implementation of this behavior.
First, take a look at the declaration of the `EnemyObject` class.
It again inherits from the `CircleGameObject` class, so it already
has a corresponding circle shape data and behavior attached to it.
Moreover, the `getKind()` method of the `EnemyObject` class 
distinguish the enemy objects from other kind of objects (player and consumable)
by returning the `GameObjectKind::ENEMY` value.

We have also already implemented for you the movement behavior of the `EnemyObject`.
To do so, we have added two new fields to the objects of this class:
- `velocity` field is vector storing the direction and speed of the current velocity of the object;
- `updateTimer` field stores the time elapsed since the last update of the object's velocity.

The method `getVelocity()` simply returns the value of `velocity` field.
The method `update(sf::Time delta)` is responsible for periodically updating the velocity of the object. 
It takes as an argument the amount of time elapsed since the last update.
The implementation simply checks if the overall amount of elapsed time
is greater than the predefined time period (1 second), 
and if so, it resets the velocity to a new randomly generated one.

Now your task is to implement the rest of enemy objects functionality.

The easy part is to implement the `getTexture` method, 
that should return a new special texture for the enemy objects.
This texture has a corresponding id --- `GameTextureID::BLACKHOLE`.

The harder part is to implement the collision behavior.
When an enemy object collides with the player object, the player object should become inactive.
This can be achieved by setting the status of the player object to `DESTROYED`.
However, an enemy object does not have direct access to the `setStatus` method of the player object.
So in order to implement the desired behavior, you actually need to 
modify the `onCollision` method of the `PlayerObject` class, not the `EnemyObject` class!

<div class="hint">

In the implementation of the `PlayerObject::onCollision` method, 
do not forget to check that the collision occurred with the enemy object,
not an object of some other kind!

</div>

Notice that from the point of view of the consumable objects, 
the player and the enemy objects behave similarly, 
so you do not need to modify their behavior. 