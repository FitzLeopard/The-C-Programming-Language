## Notes on Exercises of Chapter 3

### Review on my solution and standard solution of Exercise 3-1

The standard solution is almost the same as the original solution in run time cost. But my solution is different and needs more complicated analysis.

But both of them are less readable than the one in K&R.

### 3-4

The largest negative number is $-(2^{\text{wordsize}-1})$. In the original version of `itoa`, `n` will be changed to `-n` if it is negative. However, changing the largest negative number to `-n` will lead to overflow of `int`, with the consequence unpredictable.

My new version of `itoa` in `3-4.c`  fixes this issue. It doesn't change the value of `n`. Instead, it will use the variable `sign` to adjust the number extracted from `n`.

But I don't think my version is machine-independent because it uses `%` on negative number. So I wrote the version in `3-4-independent.c`. I think it is independent of machine because it does not use `%`, only `/` was used.

But that does not seem to be true. The direction of truncation of `/` for negative number is also machine dependent!

### Review on my solution and standard solution of Exercise 3-3

With proper use of `while` and increment operator, the standard solution is far more compact than my solution.

### Review on my solution and standard solution of Exercise 3-4

I get the following information about division and module in C from http://en.cppreference.com/w/c/language/operator_arithmetic

![](/home/rivers/Pictures/TruncationOfDivisionInC.png)

![](/home/rivers/Pictures/SignOfModuleInC.png)

I think in the time of C89, there is no standard way for machine-independent `itoa` for `INT_MIN`.
