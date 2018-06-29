/*
 *  Date: 2018-06-29
 *  Exercise 5-6 of K&R
 *  By Rivers
*/

#include<stdio.h>

#define MAX 20

char *itoa(char *des, int n);
char *reverse(char *s);

int main()
{
    char s[MAX];
    int n;

    scanf("%d", &n);
    itoa(s, n);
    printf("%s\n", s);

    return 0;
}

/* itoa: convert n into string des */
char *itoa(char *des, int n)
{
    int sign = n < 0 ? -1 : 1;
    char *odes = des;   // original des

    if (n < 0) {
        n = -n;
    }
    do {
        *des++ = n % 10 + '0';
        n /= 10;
    } while (n);
    if (sign < 0) {
        *des++ = '-';
    }
    *des = '\0';
    reverse(odes);

    return odes;
}

/* reverse: reverse string s, return the result */
char *reverse(char *s)
{
    char *e = s, *os = s;    // os for original s

    while (*e) {
        ++e;
    }
    --e;
    while (s < e) {
        char tmp = *s;
        *s = *e;
        *e = tmp;
        ++s;
        --e;
    }

    return os;
}