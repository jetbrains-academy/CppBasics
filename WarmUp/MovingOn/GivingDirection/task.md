It is time to provide some direction to the movement of our planet! 
In this step we will allow the user of the program to control the planet 
using the arrow keys on the keyboard.    

To model the direction of a movement, we will need yet another new data type.

```c++
enum Direction {
    North,
    East,
    South,
    West
};
```

Here, we define the 
[_enumeration_](https://en.cppreference.com/w/cpp/language/enum) 
type, hence the keyword `enum`. 
The value of the enumeration type can be one of the alternatives 
listed in the definition of the enumeration.

```c++
Direction direction = North;
```

To handle user input, that is, the event of pressing a certain arrow key, 
we have already added the relevant code in [main.cpp](course://WarmUp/MovingOn/GivingDirection/src/main.cpp).
You can try to find and understand this new piece of code. 
If you do not understand something yet, do not worry.
At the current step, your job is to simply implement another function: 

```c++
Point2D getDirection(Direction direction)
``` 

To give a direction, you need to compute the _unit vector_ of this direction.
For example: 
* if the direction is `North`, the unit vector equals `{ 0.0f, -1.0f }`;
* if the direction is `East`, the unit vector equals `{ 1.0f, 0.0f }`;  
and so on. 

In order to decide which direction is passed, you can use the `case` statement:

```c++
switch (direction) {
    case North:
        std::cout << "North";
        break;
    case East:
        std::cout << "East";
        break;
    default:
        std::cout << " ";
        break; 
}
```  

The execution proceeds as follows. 
The actual value of the variable `direction` is inspected, and then: 
* if it is equal to `North`, the code in the `case North:` branch is executed; 
* if it is equal to `East`, the code in the `case East:` branch is executed;
* otherwise, the code in the `default:` branch is executed.

Notice that the `break` statement is required to leave the branch. 
Otherwise, the execution does not exit the branch and proceeds to the next branch:

 ```c++
switch (direction) {
    case North:
        std::cout << "North" << " ";
    case East:
        std::cout << "East";
    // if direction is North, then prints "North East"
    // if direction is East, then prints "East"
}
```

Inside the function, instead of `break`, you can also use `return` to exit 
from the `case` branch and the whole function.
