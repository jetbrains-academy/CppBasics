## Your first "Hello Words" in C++ 
 
Let's start our journey into C++ with something simple. 
Let's write a program that will say "Hello World!"

In C++, the entry point to the program is a distinguished function named `main`. 
Your task is to add code to this function so that it will print 
the string `"Hello World!"`

To print something in C++, one can use the following syntax:

```c++
std::cout << "Text to be printed\n";
```

Note the special character `'\n'` at the end of the printed message.
This is the so-called "newline" character. 
It is not printed on the screen itself, instead 
it causes the cursor to move to the beginning of the next line. 
This means that anything printed after `\n` will start on a new line.
Therefore, the following code 

```c++
std::cout << "Line 1\n";
std::cout << "Line 2\n";
```

will print two lines:

```text
Line 1
Line 2
```

In order to successfully finish this task, make sure to 
also end the line after `"Hello World!"` string. 