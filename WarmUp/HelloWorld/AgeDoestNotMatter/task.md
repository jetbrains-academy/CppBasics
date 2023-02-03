## Age does not matter!
 
As a final quiz in this lesson, we kindly ask you 
to write another program.
In addition to the person's name, 
this program  should ask about their age. 
The program should print "Hello Username" 
and then "Age" on the next line, 
where "Username" and "Age" should be substituted by the actual 
data given to the program.
 
The age of a person is an integer value, so 
we will store it in a variable of type `int`. 

```c++
int age = 0;
```

In order to finish a line and go to the next one, you need 
to supply a special value `std::endl` (read as endline)
to `std::cout`.

```c++
std::cout << "Hello" << std::endl << "World";
// World will be printed on the second line. 
```
