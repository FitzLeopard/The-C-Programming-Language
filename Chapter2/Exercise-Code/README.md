## Notes on Exercises

### Review on my solution and standard solution of 2-1

My solution only prints the word length of each type.

The standard solution employs two methods to solve the problem. The first one is using a typical header `limits.h`. And all the variable needed is listed in the source code `2-1-standard-header.c`.

Another is to use bitwise operation. This method needs some knowledge of representation of numbers in computer, such as `(char)((unsigned char)~0 >> 1)`

I will revisit this problem.

### Review on my solution and standard solution of 2-2

My solution try to maintain the expressions in the original loop like `i < lim - 1`. But the whole program turned out to be very hard to read and not very elegant.

The standard solution did a good Job.

I will revisit this problem.

### Review on my solution and standard solution of 2-8

My solution is wrong. I corrected it. It was wrong because I didn't take the situation $n>wordlength$ into consideration. I corrected it by adding this line `n %= wordlength`. 

The standard solution is more compact and elegant.

I will revisit this problem.

### 2-9

In a two's complement number system, `x &= x - 1` will remove the rightmost 1-bit in `x`.  Why?

Suppose that we have a number and its 2-radix representation. If it is not 0, it must have at least one 1-bit. So it must have the following format---$X10\cdots0$. $X$ is a lot of bits. So `x-1` will be $X01\cdots1$. It is obvious that `x & (x - 1)` only eliminates the rightmost 1-bit of `x`.
