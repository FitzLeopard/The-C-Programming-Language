/*
 *  Date: 2018-06-29
 *  Exercise 5-5 of K&R
 *  By Rivers
*/

#include<stdio.h>

#define MAX 1000

char *StrNCpy(char * des, const char *src, int n);

int main()
{
    char s1[MAX], s2[MAX];
    int n;

    scanf("%s %s", s1, s2);
    scanf("%d", &n);
    printf("%s\n", StrNCpy(s1, s2, n));

    return 0;
}

char *StrNCpy(char * des, const char *src, int n)
{
    char *odes = des;   // original des

    while (--n && (*des++ = *src++))
        ;
    return odes;
}