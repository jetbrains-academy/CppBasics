So far, we have learned that the program's memory
consists of individual addressable memory cells.
We have also learned how to take the addresses of variables in memory and
how to store and move them around using pointers.
What we have not yet learned is how memory
is allocated and freed once the variables occupying
this memory are no longer needed.
As in our everyday life, it is very important to recycle resources —
in our case, the program's memory. If a program keeps allocating
memory for new variables without ever deallocating it,
it could eventually exhaust all the available memory on the user's machine.

In most modern programming languages, memory deallocation is performed
automatically, behind the back of the programmer, by the
language subsystem known as a
[garbage collector](https://en.wikipedia.org/wiki/Garbage_collection_(computer_science)).
While this is indeed very convenient, since it frees
the programmer from the burden of managing the memory manually,
garbage collection comes with certain costs:

* It consumes a portion of the program's runtime to search for unused memory, and
* It can introduce unexpected pauses, which can negatively impact the program's responsiveness
  and throughput.

C++ tends to give the programmer maximum control over how the program runs.
This includes the possibility to manually manage memory allocation and deallocation.

In C++, there are three distinct memory regions governed by
different memory management policies:

* global static memory,
* stack memory, and
* dynamic heap memory.

In the following steps, you will learn about all of them.

![Memory Layout](../../../images/memory.svg)
