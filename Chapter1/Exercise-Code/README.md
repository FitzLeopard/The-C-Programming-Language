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

### 1-19

Since the *prototype* in the problem is similar to `reverse(s)`, I write the function `void reverse(char s[])`. But the function will be more efficient if we are allowed to pass the length of string to it.