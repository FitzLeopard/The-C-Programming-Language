## Notes on Chapter 1 Exercises

### 1-2

Get an error message

```
1-2.c: In function ‘main’:
1-2.c:11:9: warning: unknown escape sequence: '\c'
  printf("hello, world\n\c");
         ^~~~~~~~~~~~~~~~~~
```

### 1-4

Get the formula
$$
F=\frac{9}{5}\times C + 32
$$

### 1-6

In the program I wrote I use the following statement:

```c
	while (c = getchar() != EOF)
		printf("%d", c);
	printf("%d", c);
```

The condition is equivalent to `c = (getchar() != EOF)` as the book mentioned that `!=` has higher *precedence* than `=`.

### 1-8

Initialization is significant.

### 1-16

I used the following condition to test `Getline` overflow.

```C
currLen == MAXLINE - 1 && line[MAXLINE - 2] != '\n'
```

Actually, the array does not contain `MAXLINE` characters. Instead, it contains `MAXLINE - 1` characters.

#### Review on my solution and standard solution

The standard solution made modifications to both the `main` function and the `Getline` function, which is good because the function of the function still matches the name of it: it still get a line but just store them as much as possible.

My solution made modifications only to the `main` function because I think once we have designed a function, there is no need to modify it, especially one that is general enough. And the format of the output of my solution is more natural since I print both the head and tail of the long line and use `...` to connect them.

### 1-17

#### Review on my solution and standard solution

The standard solution is a little weaker than my solution, though it is shorter. My solution is capable of printing literally **arbitrarily** long lines. But the standard solution can only print the first `MAXLINE` characters of it.

### 1-19

Since the *prototype* in the problem is similar to `reverse(s)`, I write the function `void reverse(char s[])`. But the function will be more efficient if we are allowed to pass the length of string to it.

### 1-23

#### Review on my solution and standard solution

The standard solution solves the problem quiet well. But my solution works well when all the character `"` and `'` are expressed in the form of escape sequence.

I will revisit this problem.