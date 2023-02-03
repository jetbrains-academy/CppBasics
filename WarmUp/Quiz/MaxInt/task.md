Implement a function returning the maximum of two integers.

```c++
int maxInt(int a, int b);
```

For example, `maxInt(-1, 5)` should return 5.

To complete this task, you might find it convenient 
to use the conditional operator described in the hint below.

<div class="hint">

Besides the conditional `if` statement, the C++ language also has a 
[_ternary conditional operator_](https://en.cppreference.com/w/cpp/language/operator_other#Conditional_operator) 
`?:`, which can be used as an expression.

The expression `b ? t : e` evaluates to 
* `t` if `b` evaluates to `true` (or any non-zero integer value),
* `f` if `b` evaluates to `false` (or zero integer value).

</div>

