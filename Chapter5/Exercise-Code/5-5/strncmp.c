/*
 *  Date: 2018-06-29
 *  Exercise 5-5 of K&R
 *  By Rivers
*/
#include<stdio.h>

#define MAX 1000

int StrNCmp(const char *a, const char *b, int n);

int main()
{
    char s1[MAX], s2[MAX];
    int n;

    scanf("%s %s", s1, s2);
    scanf("%d", &n);
    printf("%d\n", StrNCmp(s1, s2, n));

    return 0;
}

/* StrNCmp: compare at most the first n chars in a and b
   return:
   1  - a is larger than b
   0  - a is equal to b
   -1 - a is less than b                                */
int StrNCmp(const char *a, const char *b, int n)
{
    while (--n && *a == *b && *a != '\0' && *b != '\0') {
        ++a;
        ++b;
    }
    if (*a < *b) {
        return -1;
    }
    else if (*a > *b) {
        return 1;
    }
    else {
        return 0;
    }
}