Because of the stack memory management policy, 
addresses of local variables can be passed to other functions 
deeper into the call stack, but they can never be returned 
from the function to the caller, since when the function 
returns, the memory occupied by its local variables is deallocated.

Given a concrete example, the following code snippet 
is completely valid – the address of the local variable
defined inside the body of the `caller` function is passed to the function `callee`.

```c++
void callee(int* p) {
    std::cout << p << " -> " << *p << "\n";
}

void caller() {
    int a = 42;
    callee(&a);
}
```

Indeed, since `callee` is called from `caller`, the stack frame associated 
with `caller` cannot be popped from the stack earlier than 
the stack frame of `callee`.
Thus, the memory occupied by the variable `a` is allocated 
the whole time while `callee` is being executed.

On the contrary, the following code snippet is erroneous.

```c++
int* escape() {
    int a = 42;
    return &a;
}

void escapeCaller() {
    int* p = escape();
    std::cout << p << " -> " << *p << "\n";
}
```

In this case, the address of the variable `a` _escapes_ the function. 
It is passed to the caller, and at the time when it 
is accessed, the stack frame of `escape` is already popped
from the stack, and thus, the memory occupied by `a` is deallocated.
If you try to compile and run the above code, 
the program is likely to crash or print some garbage. 

Note that a similar error occurs when the address of a local variable
is stored in a global variable.

```c++
int* q = nullptr;

void escapeGlobal() {
    int a = 42;
    q = &a;    
}

void escapeGlobalCaller() {
    escapeGlobal();
    std::cout << q << " -> " << *q << "\n";
}
```