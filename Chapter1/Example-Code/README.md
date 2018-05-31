## Notes on Example Code

### Counting character

The unexpected result of `wc` and `CountingChar.c` is a result of convention.

The convention is that every file should end with a newline. And **Vim** will add a newline to the file no matter whether there is one.

### Counting Word

The program `CountingWord.c` almost has the same function as the hashed command `wc`.

#### Character Array

The standard library has a `getline` function so I rename the function as `Getline`.

