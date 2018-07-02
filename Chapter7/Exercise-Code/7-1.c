/*
 *  Date: 2018-07-02
 *  Exercise 7-1 of K&R
 *  By Rivers
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void lower(void);
void upper(void);

int main(int argc, char *argv[])
{
    if (strstr(argv[0], "lower") != 0) {
        lower();
    }
    else if (strstr(argv[0], "upper") != 0) {
        upper();
    }
    else {
        printf("Your file name is: %s\n", argv[0]);
        printf("Usage: change the file name to 'lower' or 'upper'\n"
               "in order to get the lower or upper case output, respectively.\n");
    }

    return 0;
}

/* change the input file to lower case */
void lower(void)
{
    int c;

    while ((c = getchar()) != EOF) {
        putchar(tolower(c));
    }
}

/* change the input file to upper case */
void upper(void)
{
    int c;

    while ((c = getchar()) != EOF) {
        putchar(toupper(c));
    }
}