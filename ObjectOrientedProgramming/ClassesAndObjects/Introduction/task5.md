The `Scene` class is an _abstract class_ too — 
it has pure virtual methods and thus cannot be instantiated.
This gives us the flexibility of having different implementations of the `Scene` class.

One such implementation is given by the `GameplayStaticScene` subclass
(see files `statscene.hpp` and `statscene.cpp`).
This scene implementation is called static because it contains only
static predefined number of game objects: single player object and single consumable object.
It is certainly a downgrade from our previous version implementation of the game, 
when we learned how to create objects dynamically with the help of the linked lists.
Do not worry, we will restore this feature soon.
But for now, let us work with the static scene.

The `Scene` class has a certain peculiarity compared to the `GameObject` class —
there could exist single unique `Scene` per one game instance.
We can express this in the code with the help of another C++ feature: `static` modifier.

First, note that the `Scene` class has one method that stands out from the others:
it is `create()` method that has `static` modifier in front of it.
The `static` modifier, applied to a class member (either field or method),
turns this member into a _static_ member. 

Static members are not associated with the objects, instead they are associated with the class itself.
This means that in order to access a static member, you do not need an instance of the class at hand.
Instead, static members are accessed through the class name:

```c++
// obtains a scene instance by calling static method `create`
Scene* scene = Scene::create();
```

Static members provide a convenient way to associate some methods or data fields with the class itself.
For example, the `create` method shown above provides an ability to instantiate 
the scene object, without revealing the actual implementation to the user of the method
(note that it returns `Scene*` instead of `GameplayStaticScene*`).
Moreover, it gives us a way to ensure that only one scene is created per each game run. 
How we can achieve that — well, with the help of the `static` modifier again.

When applied to the declaration of local variables inside functions, 
`static` modifier has a different meaning.
It allows creating a _static variable_ that survives and preserves its value between the function calls.
Such variables are actually stored inside the static memory region of the program,
instead of the stack memory region where the other local function's variables reside, 
hence the name _static_.

```c++
int foo() {
    static int x = 0;
    return ++x;
}

// prints 1
std::cout << foo() << std::endl;
// prints 2
std::cout << foo() << std::endl;
```

With the help of the `static` modifier, it becomes possible to
declare static `GameplayStaticScene` variable inside `Scene::create` method 
and return a pointer to this variable.

<div class="hint">

Note that in this case, the address escape error does not occur.
Because the `static` variable resides in the static memory region, it lives thought the whole program execution time.
Thus, it is safe to return the address of this variable from the function.

</div>

Please implement the `create` method as described above.
If you do this correctly, you will be finally able to run the refactored game application 
and see the planet and star objects on the screen.
