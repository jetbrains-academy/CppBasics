Implement a function to concatenate two C-style strings:

```c++
char* concat(const char* fst, const char* snd); 
```

This function should allocate a sufficient amount of memory
and copy the contents of two strings, placing the null-terminator character `\0`
at the end of the resulting string.
You can assume that only non-null pointers will be passed to `concat`.

Here is an example of `concat` usage:

```c++
const char* hello = "Hello ";
const char* world = "World!";
const char* helloWorld = concat(hello, world);
// should print "Hello World!" 
std::cout << helloWorld << "\n";
```

<div class="hint">

Note that in the C standard library, there is a similar function: 

```c++
char* strcat(char* dest, const char* src);
```

However, unlike the `concat` function that you need to implement,
the `strcat` function does not itself allocate memory for the 
concatenated string. Instead, it expects that the string `dest`, 
passed as the first argument, is backed up with a 
sufficient amount of memory allocated to store the result. 
It then stores the result into `dest`, thus modifying
the original string passed as an argument.

</div>
