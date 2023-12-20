The `Scene` class is an _abstract class_ too —
it has pure virtual methods and thus cannot be instantiated.
This gives us the flexibility of having different implementations of the `Scene` class.

One such implementation is given by the `GameplayStaticScene` subclass
(see files `statscene.hpp` and `statscene.cpp`).
This scene implementation is called static because it contains only
static predefined number of game objects: 
one player object, one consumable object, and one enemy object, 
which we are going to cover later in this module.
It is certainly a downgrade from our previous version implementation of the game,
when we learned how to create objects dynamically with the help of the linked lists.
Do not worry, we will restore this feature soon.
But for now, let us work with the static scene.

Despite the `Scene` class is very important and does a lot of work,
like game objects maintenance and scene drawing, 
by itself it is not responsible for managing the game itself. 
This is the purpose of another class — `GameEngine`
(see files `engine.hpp` and `engine.cpp`).
This class, in particular, controls the application window and the currently active scene. 

<div class="hint">

Another important responsibility of the `GameEngine` class is to perform scene transitions. 
As for now, this functionality would not be important for us, 
since for some time we would only have one single scene (the gameplay scene).
But later in this course it will become useful, as we will start to implement other types of scenes —
for example, a scene managing the main menu of the game.

</div>

The most important method of the `GameEngine` class is the `run()` method
which implements the main loop of the game.
In essence, the entry points of our game application is just 
a creation of the `GameEngine` object and call to its `run()` method (see file `main.cpp`).

Speaking of the creation of `GameEngine` object.
The `GameEngine` class has a certain peculiarity compared to the other classes we have seen so far —
there could exist only a single unique `GameEngine` object instance per one game instance.
We can express this in the code with the help of another C++ feature: `static` modifier.

First, note that the `GameEngine` class has one method that stands out from the others:
it is the `create()` method that has `static` modifier in front of it.
The `static` modifier, applied to a class member (either field or method),
turns this member into a _static_ member.

Static members are not associated with the objects, instead they are associated with the class itself.
This means that in order to access a static member, you do not need an instance of the class at hand.
Instead, static members are accessed through the class name:

```c++
// obtains an engine instance by calling static method `create`
GameEngine* engine = GameEngine::create();
```

Static members provide a convenient way to associate some methods or data fields with the class itself.
For example, the `create` method shown above provides an ability to instantiate the game engine object.

When applied to the declaration of local variables inside functions,
`static` modifier has a different meaning.
It allows creating a _static variable_ that survives and preserves its value between the function calls.
Such variables are actually stored inside the static memory region of the program,
instead of the stack memory region where reside the other local variables of the function 
(hence the name _static_).

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
ensure that only one engine is created per each game run.
For this, it is sufficient to declare static `GameEngine` variable 
inside `GameEngine::create` method and return a pointer to this variable.

<div class="hint">

Note that in this case, the address escape error does not occur.
Because the `static` variable resides in the static memory region, it lives thought the whole program execution time.
Thus, it is safe to return the address of this variable from the function.

</div>

Please implement the `create` method as described above.
If you do this correctly, you will be finally able to run the refactored game application
and see the planet and star objects on the screen.
