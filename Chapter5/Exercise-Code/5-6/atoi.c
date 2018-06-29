/*
 *  Date: 2018-06-29
 *  Exercise 5-6 of K&R
 *  By Rivers
*/

#include<stdio.h>
#include<ctype.h>

#define MAX 20

int atoi(const char *s);

int main()
{
    char s[MAX];

    scanf("%s", s);
    printf("%d\n", atoi(s));

    return 0;   
}

int atoi(const char *s)
{
    int sign = (*s == '-') ? -1 : 1;
    int result = 0;
    
    if (*s == '-' || *s == '+') {
        ++s;
    }
    while (isdigit(*s)) {
        result = result * 10 + *s - '0';
        ++s;
    }
    return result * sign;
}