Let us talk a little more about 
[functions](https://en.cppreference.com/w/cpp/language/functions) in C++.
If you are already familiar with the concept 
of functions, feel free to skip this step.

Functions are the basic building block of programs 
in almost every programming language.
They allow the programmer to split a complex task 
into smaller sub-problems and solve them independently.
Just like you did in the previous step. 
You only had to implement a single function `move`, 
and the rest of the work was done by our pre-written code.

Let us take a look at the syntax of functions in C++.

```c++
int sum(int a, int b) {
    return a + b;
}
```

A function has a name, arguments, a return type, and a body.
In the example above:

- `sum` is the name of the function;
- `a` and `b` are arguments given along with their type `int`;
- `int` before the function name is the return type of the function;
- `return a + b` is the body of the function enclosed in curly brackets `{}`.

Inside the function body, one can refer to any of its arguments.
Once the execution of a function reaches the `return` statement,
it completes with the result being the computation 
of the expression following the `return` keyword.

Functions with no return value have the return type `void`.

```c++
void printInt(int a) {
    std::cout << a << "\n";
}
```

To call a function from another place in the code, 
one needs to use its name and supply the sufficient number 
of arguments of suitable type. 

```c++
int c = sum(1, 2);
printInt(c); // prints 3
```

Upon the call, arguments in the body of the function
will be substituted with the actual values passed, 
control will be transferred to the body of the function, 
and when the function will terminate its 
return value will be sent back to the calling side. 
 
