Due to the stack memory management policy, 
addresses of local variables can be passed to other functions 
further down the call stack, but they can never be returned 
from the function to the caller. This is because 
the memory occupied by its local variables is deallocated when the function returns.

To give a specific example, the following code snippet 
is completely valid — the address of the local variable
defined inside the body of the `caller` function is passed to the `callee` function.

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
the entire time `callee` is being executed.

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
It is passed to the caller, and by the time it 
is accessed, the stack frame of `escape` has already been popped
from the stack. Thus, the memory occupied by `a` has been deallocated.
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
