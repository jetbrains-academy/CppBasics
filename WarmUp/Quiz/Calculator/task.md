Implement a simple console calculator app. 
It should read the user's command from the console, execute it, 
and print the result back to the user. 
The calculator should support the following commands:
* `sum n m` – summation of two numbers `n` and `m`;
* `sub n m` – subtraction of `m` from `n`;
* `mul n m` – multiplication of two numbers `n` and `m`;
* `div n m` – integer division of `n` by `m`;
* `exit` – a special command to quit the calculator app. 

Both `n` and `m` stand for integer numbers; 
you can assume that these integers lie within 
the range `-10000 ... 10000`.

An example run of your application should look like this:

* the user enters a command

```c++
mul 3 4
```

* the app prints the result

```c++
12
```

* the user enters the next command

```c++
sum -1 12
```

* the app prints the result

```c++
11
```

* finally, the user enters the command to quit

```c++
exit
```

* and the app should terminate in response.

In the case when the user provides an incorrect command, 
the app should politely respond and print the following message:

```c++
Sorry, could not understand your command
```

Then it should wait for the next command.

For this task you might find useful the information 
about the `break` and `continue` statements in C++ provided in the hint below.

<div class="hint">

The `break` and `continue` statements allow you to 
exit from a loop early, similar to how you would exit a 
function early using the `return` statement.

When the execution reaches the `break` 
[statement](https://en.cppreference.com/w/cpp/language/break), 
it exits the nearest innermost loop statement (either `for` or `while`):

```c++
for (int i = 1; i <= 4; ++i) {
    if (i > 2) {
        break;
    }
    std::cout << i << " ";
}
// prints 1 2
```

When the execution reaches the `continue` 
[statement](https://en.cppreference.com/w/cpp/language/continue), 
it skips the rest of the nearest innermost loop body
and starts to execute the next iteration of the said loop
(checking the loop condition first).

```c++
for (int i = 1; i <= 4; ++i) {
    if (i == 2) {
        continue;
    }
    std::cout << i << " ";
}
// prints 1 3 4
```

</div>