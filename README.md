[![official project](https://jb.gg/badges/official.svg)](https://confluence.jetbrains.com/display/ALL/JetBrains+on+GitHub)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

# C++ Basics

The course is designed for beginners who want to learn the basics of the C/C++ language.

The main goal of the course is to introduce the C++ language, its philosophy of zero-cost abstractions;
its distinctive features compared to other languages, and, in particular, manual memory management,
and its areas of use, such as high-performance applications, graphics, and system programming.
After successfully completing this course, you will be able to read and write C++ code
and develop your own programs of medium complexity. 

During this course, you will be developing a simple 2D arcade game.
In this game, the player controls a planet that moves through space, consuming smaller asteroids and dodging black holes.
With each new topic covered, you will improve the game by implementing new functionality based on the concepts you have learned.
In the end, you will get a working game, which you can further modify as you like.

Some of the topics covered in the course are listed below.
* Basic programming primitives in C++.  
* Manual memory management.  
* Object-oriented programming in C++. 
* Template meta-programming and functional programming features of C++. 
* Overview of the standard library. 
* Multi-file projects and program compilation process overview. 

The released part of the course covers C++ basic programming primitives.
Stay tuned for more parts of our course coming soon!

## Technical requirements

Before starting this course, check the following requirements.
1. Your computer needs to have a stable internet connection. 
2. [Git](https://git-scm.com/) version control system needs to be installed on your computer. 
3. Make sure that the path to the root folder of the course does not contain spaces, special characters, or non-latin characters.

The course is integrated into the [CLion IDE](https://www.jetbrains.com/clion/),
which has only a commercial license.
You may request a trial license in order to complete the course.
If you have already used your trial license before, please contact us at 
[education@jetbrains.com](mailto:education@jetbrains.com).

## Getting started

This course is available on JetBrains Marketplace and can be installed from the
[CLion](https://www.jetbrains.com/clion/) directly, but you can also
install the the [EduPlugin](https://plugins.jetbrains.com/plugin/10081-edutools), and open this course 
in [course creator mode](https://plugins.jetbrains.com/plugin/10081-edutools/docs/educator-start-guide.html), 
create a [course preview](https://plugins.jetbrains.com/plugin/10081-edutools/docs/educator-start-guide.html?section=C%2B%2B#preview_course) or  
a [course archive](https://plugins.jetbrains.com/plugin/10081-edutools/docs/educator-start-guide.html?section=C%2B%2B#course_distribution).

## Course Content

The course is split into following modules, 
with each module covering specific topics and aspects of the C++ language.  


* __Warm Up__
  * variables declaration and initialization
  * primitive types: `int`, `double`, `char`, etc
  * `std::string` type to work with text data
  * basic input and output: `std::cin`, `std::cout`
  * basic control-flow: `if`, `switch`, `for`, `while`, `do-while` 
  * functions declaration and usage
  * custom data types: `struct` and `enum`
  * _(static)_ arrays
  * random numbers
  * program debugging in IDE
  
* __Memory Management__
  * size of a type, `sizeof` operator
  * address of variable, address of operator `&`
  * pointers, `nullptr`, dereference operator `*`, pointer arithmetic
  * primitive types, array and custom data type (`struct`, `enum`) memory layout
  * function pointers
  * memory regions: static, stack, and heap memory  
  * dynamic memory allocation and freeing: `malloc` and `free`
  * memory errors: address escape, out-of-bounds accesses, memory leaks, use after free, double free
  * detecting memory errors in IDE with dynamic code analysis: valgrind and memory sanitizer
  * constantness and mutability, `const` keyword
  * references
  * passing arguments by value, by reference, or by pointer
  * type cast operators: C style casts, `static_cast`, `reinterpret_cast`
  * C style strings

* __Object-Oriented Programming and Ownership Semantics__
  * operators overloading
  * classes and objects
  * class fields and methods, `virtual` methods
  * abstract classes and interfaces 
  * inheritance, polymorphism, and encapsulation
  * visibility modifiers: `public`, `protected`, and `private`
  * class invariants
  * `static` members
  * `class` vs `struct`, plain old data types (POD)
  * constructors and destructors
  * `explicit` constructor
  * object's lifetime, storage duration vs lifetime
  * `new` and `delete` operators
  * placement `new` operator
  * copy and move constructors
  * copy and move assignment operators
  * copy-and-swap idiom
  * ownership and move semantics
  * resource acquisition is initialization idiom (RAII)
  * smart pointers: `std::unique_ptr`, `std::shared_ptr`, and `std::weak_ptr`

* __TBA__ ...
 
