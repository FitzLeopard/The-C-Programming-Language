## Notes on Exercises of Chapter 3

### 3-4

The largest negative number is $-(2^{\text{wordsize}-1})$. In the original version of `itoa`, `n` will be changed to `-n` if it is negative. However, changing the largest negative number to `-n` will lead to overflow of `int`, with the consequence unpredictable.

My new version of `itoa` in `3-4.c`  fixes this issue. It doesn't change the value of `n`. Instead, it will use the variable `sign` to adjust the number extracted from `n`.

But I don't think my version is machine-independent because it uses `%` on negative number. So I wrote the version in `3-4-independent.c`. I think it is independent of machine because it does not use `%`, only `/` was used.