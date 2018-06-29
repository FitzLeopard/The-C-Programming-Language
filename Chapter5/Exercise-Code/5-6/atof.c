/*
 *  Date: 2018-06-29
 *  Exercise 5-6 of K&R
 *  By Rivers
*/

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX 1000

double atof(const char *s);

int main()
{
    char s[MAX];

    scanf("%s", s);
    printf("%g\n", atof(s));

    return 0;   
}

double atof(const char *s)
{
    int sign = (*s == '-') ? -1 : 1;
    int expo = 0;
    double power = 1.0, result = 0.0;

    if (*s == '-' || *s == '+') {
        ++s;
    }
    while (isdigit(*s)) {
        result = result * 10 + *s - '0';
        ++s;
    }
    if (*s == '.') {
        ++s;
    }
    while (isdigit(*s)) {
        result = result * 10 + *s - '0';
        power *= 10;
        ++s;
    }
    if (*s == 'e' || *s == 'E') {
        ++s;
    }
    expo = atoi(s);   
    for (int i = 0; i < expo; ++i) {
        power /= 10;
    }
    for (int i = expo; i < 0; ++i) {
        power *= 10;
    }
    return result / power;
}