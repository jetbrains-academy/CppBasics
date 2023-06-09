## Introduce Yourself!
 
Ok, we hope that was easy. 
Next, we invite you to introduce yourself!

Write a simple program that will ask the name of a person
and then print the string "Hello Username" 
(where "Username" should be substituted by the actual name given to the program).

To do this, you will need to learn a few other words in C++.

First, you will need to use a _variable_ to store the name of the user. 
A suitable variable is already declared in the template solution. 

```c++
std::string name;
```

Next, to input some data into a C++ program, use the following syntax:

```c++
std::cin >> x;
```

where `x` is the variable you want to fill with data.

In order to print several strings, 
just list them consequently and separate by `<<`.

```c++
std::cout << "Hello " << "World!" << "\n";
```

You can print variables using the same syntax as for printing strings.

Note that all the above lines of code end with `;`.
In fact, a C++ program consists of _statements_, 
that is individual computation steps.
Semicolon `;` signifies the end of a statement.
You can build your program from individual statements 
using `;` to separate them. It is recommended to put each 
statement on a separate line.

<div class="hint">

In order to successfully complete this task,
make sure to end the line with newline `'\n'` character.
In general, in C++ programming it is a good practice 
to always put `'\n'` character at the end of the line, 
even if the printing statement is the last statement 
and the program terminates immediately after executing it.

</div>