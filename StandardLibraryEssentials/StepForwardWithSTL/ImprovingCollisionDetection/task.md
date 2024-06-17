Let's take a look at the current implementation of the collision detection in `update` function inside `dynscene.cpp`.

```cpp
void GameplayDynamicScene::update(sf::Time delta) {
    // update the objects' state
    objects.foreach([delta] (GameObject& object) {
        object.update(delta);
    });
    // move objects according to their velocity and elapsed time
    objects.foreach([this, delta] (GameObject& object) {
        move(object, delta);
    });
    // compute collision information for each pair of objects
    objects.foreach([this] (GameObject& object) {
        objects.foreach([this, &object] (GameObject& other) {
            if (&object != &other) {
                detectCollision(object, other);
            }
        });
    });
    // update the list of objects
    updateObjectsList();
}
```

We can see that there is a flaw, that we need to fix before counting any points: all collisions are detected twice due to simplicity of a foreach loop.

In order to fix this, we need to iterate only over objects that have not been checked yet. We can do this by keeping `foreach` as an outer loop and adding a `while` loop inside it, which will cover all unchecked objects. 

To do this, we can implement a new function in `gobjectlist.cpp` file, named `findNext`, which will return the next object of the list, or `nullptr` if there are no more objects to check.