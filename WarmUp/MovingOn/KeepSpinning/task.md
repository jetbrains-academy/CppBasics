Besides the `for` loop statement, C++ also provides the 
`while` [loop statement](https://en.cppreference.com/w/cpp/language/while) 
and the `do-while` [loop statement](https://en.cppreference.com/w/cpp/language/do).

```c++
int x = 3;
while (x > 0) {
    std::cout << x << " ";
    --x;
}
std::cout << "...";
// prints "3 2 1 ..." 
```

The `while` loop consists of a condition expression and the loop body. 
The body of the `while` loop statement is executed while 
the condition expression evaluates to `true`.
Note that the body may not be executed even once if the 
condition evaluates to `false` from the beginning.
If you need the body to be executed at least once, 
use the `do-while` loop statement.

```c++
int x = 3;
do {
    std::cout << x << " ";
    --x;
} while (x > 0);
std::cout << "...";
// prints "3 2 1 ..." 
```

Here are some general recommendations on what type of loop statement to use.

* Prefer the `for` loop if you need to iterate over an array or some other collection of elements.
* Prefer the `while` loop if you need to repeat the execution of some block of code 
  until a certain condition is met. If additionally you want to be sure that 
  this block of code is executed at least once, then use the `do-while` loop.   

For example, the `while` or `do-while` loop is commonly used in interactive applications 
to implement the so-called "main loop" of the application. 
In this case, on each iteration of the loop, the program reads 
input from the user and then calls some function to handle user-provided data
until the user signals to close the application.

```c++
// DoNothing application. 
// It reads user input and does nothing with it
// unless the user passes the "exit" string to terminate the application.
std::string input;
do {
    std::cin >> input;
} while (input != "exit");
```