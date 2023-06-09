Implement a function that splits the given C string 
into substrings separated by any of the given separator characters:

```c++
size_t split(const char* str, const char* seps, char**& res);
```

Here is an example of the usage of this function:

```c++
const char* str = "Hello, World!";
const char** res = nullptr;
size_t size = split(str, " ,!", res);
// should print 2
std::cout << size << "\n";
// should print "Hello"
std::cout << res[0] << "\n";
// should print "World"
std::cout << res[1] << "\n";
```

This function takes as its first argument `str` the string that needs to be split.
The second argument `seps` is a string consisting of separator characters.
The third argument `res` is a reference to a pointer to the resulting array of strings –
the function should store the pointer to the resulting array into this argument.
Finally, the function should return the size of the resulting array, 
that is the number of split substrings.

If the original string contains several subsequent separator characters,
they should be all skipped. That is, the function should not
add to the result any empty substrings occurring "between" subsequent separator characters.

If there are no substrings, the function should return `0` 
and store `nullptr` into the `res` argument.

Otherwise, the function should allocate a sufficient amount of memory to store 
the resulting array and all the substrings. Each substring has to be allocated separately.
Going back to the example above, the user should be able to free the 
memory allocated by the function in the following manner:

```c++
free(res[0]);
free(res[1]);
free(res);
```

<div class="hint">

In order to implement `split`, you might find useful the following 
functions from the standard library:

- [`strpbrk`](https://en.cppreference.com/w/cpp/string/byte/strpbrk) --- 
      searches for the first occurrence of the separator character in the given string;
- [`strspn`](https://en.cppreference.com/w/cpp/string/byte/strspn) --- 
      returns the size of a substring from the given string, consisting of only the separator characters;
- [https://en.cppreference.com/w/cpp/string/byte/strncpy](https://en.cppreference.com/w/cpp/string/byte/strncpy) ---
      copies a certain number of characters from one string to another. 

```c++
const char* str = "Hello, World!";
// returns ", World!" --- (str + 5) pointer
const char* substr = strpbrk(str, " ,!");
// returns 2
strspn(substr, " ,!"); 
// copies substring "Hello"
char hello[6] = { 0 };
strncpy(hello, str, 5);
```

</div>



