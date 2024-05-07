In the C++ programming community, you can often hear about the C and C++ styles of programming. 
You might also find examples of these different styles in various C/C++ projects.
So what exactly are those two styles?

Initially, the C++ language was developed as an extension of the C language.
Even as of today, most of the code written in C can also be compiled by C++ compilers.
However, in general, C is not a strict subset of C++, meaning that 
there are a lot of various [incompatibilities](https://en.wikipedia.org/wiki/Compatibility_of_C_and_C%2B%2B) 
between these languages.
Besides that, there are many language features, idioms, and patterns that differ in C and C++.
These differences give rise to the aforementioned C and C++ styles.

It is important to learn to read C-style code, even if you plan to follow purely the C++ style in the future.
As of today, the C language has become a "cross-platform assembly language",
a universal low-level language that other languages often use to communicate
with each other, the underlying operating system, and other system-level software.
Many C++ projects also need to integrate with libraries written in C,
which occasionally requires using the C coding style.

We have already seen some examples of the two styles in our course.

- So far, we have used C++ style primitives for input and output (I/O), 
  namely `std::cout` and `std::cin`.
  The C language has its own distinct API for performing I/O. 
  We will revisit this API later. 

- In the first module, we used the function `rand()` to generate random numbers. 
  In fact, it is part of the C standard library. C++ provides more advanced
  (and thus more complex to grasp) facilities for random number generation, 
  which we will touch upon later in the course.

- Almost all memory management functions we've learned in this module
  (like `malloc` and `free`) are considered low-level C-style primitives. 
  C++ provides other alternatives, which we'll delve into in the next module. 
  C++ memory management primitives are tightly connected to the
  features we have not yet studied, such as the _object system_ and the concept of _resource ownership_. 
  On the contrary, C-style memory management is "closer to the ground", 
  and thus, it is important to first build a mental model around it before moving on to more complex concepts.

In this lesson, we will study two other important primitives
expressed differently in C and C++ styles: namely, type casts and strings.
