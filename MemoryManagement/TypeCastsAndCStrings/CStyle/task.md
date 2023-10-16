In the community of C++ programmers, you can often hear about the C style and C++ style of programming. 
You might also find examples of usage of these different styles in various C/C++ projects.
So what are those two styles?

Initially, the C++ language was developed as an extension of the C language.
Even as of today, most of the code written in C can also be compiled by C++ compilers.
However, in general, C is not a strict subset of C++, meaning that 
there are a lot of various [incompatibilities](https://en.wikipedia.org/wiki/Compatibility_of_C_and_C%2B%2B) 
between these languages.
Besides that, there are a lot of language features, idioms, and patterns that differ in C and C++.
These differences give rise to the mentioned C and C++ styles of doing things.

It is important to learn to read C-style code, even if you plan to follow purely the C++ style in the future.
As of today, the C language has become a "cross-platform assembly language",
a universal low-level language that other languages often use to communicate
with each other, with underlying operating system, and with other system-level software.
Many C++ projects also need to integrate with libraries written in C,
and thus occasionally use the C style of coding.

We have already seen some examples of the two styles in our course.

- So far, we have used the C++ style primitives for input and output (I/O), 
  that is `std::cout` and `std::cin`.
  The C language has its own distinctive API for doing I/O. 
  We will revisit this API later. 

- In the first module, we used the function `rand()` to generate random numbers. 
  In fact, it is part of the C standard library. C++ provides more advanced
  (and thus more complicated to grasp) facilities for random number generation, 
  which we are going to touch later in the course.

- Almost all memory management functions we learned in that module
  (like `malloc` and `free`) are considered low-level C-style primitives. 
  C++ provides other alternatives, which we are going to study in the next module. 
  It is because C++ memory management primitives are tightly connected to the
  features we have not studied yet, that is _object system_ and the concept of _resource ownership_. 
  On the contrary, C-style memory management is "closer to the ground", 
  and thus, it is important to first build a mental model around it before going to more complex concepts.

In this lesson, we are going to study two other important primitives,
expressed differently in C and C++ styles: namely, type casts and strings.