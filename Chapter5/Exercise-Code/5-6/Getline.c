/*
 *  Date: 2018-06-29
 *  Exercise 5-6 of K&R
 *  By Rivers
*/

#include<stdio.h>

#define MAX 1000

int Getline(char *line, int lim);

int main()
{
    int len;
    char line[MAX];

    while ((len = Getline(line, MAX)) > 0) {
        printf("length:%3d\n", len);
        printf("%s", line);
    }

    return 0;
}

int Getline(char *line, int lim)
{
    int c, olim = lim;  // olim for original lim

    for (; lim-- && (c = getchar()) != EOF && c != '\n'; ++line) {
        *line = c;
    }
    if (c == '\n') {
        *line++ = c;
        --lim;
    }
    *line = '\0';
    
    return olim - lim - 1;
}