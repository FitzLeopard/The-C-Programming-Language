/*
 *  Date: 2018-07-02
 *  Exercise 7-3 of K&R
 *  By Rivers
*/

#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

void minprintf(char *fmt, ... );

int main()
{
    int myInt = 10;
    char *string = "Hello, world";

    minprintf("%s * %d\n\n", string, myInt);

    return 0;
}

/* minprintf: a simplified private printf */
void minprintf(char *fmt, ... )
{
    va_list ap;
    char *p, *sval;
    char arg[10];
    int ival, i;
    double dval;

    va_start(ap, fmt);  /* make ap point to 1st unnamed arg */
    for (p = fmt; *p; ++p) {
        if (*p != '%') {
            if (*p != '\\') {
                putchar(*p);
            }
            else {      /* handle the escape sequence */
                arg[0] = *p;
                arg[1] = *++p;
                arg[2] = '\0';
                printf(arg);
            }
            continue;
        }
        i = 0;
        while (!isalpha(*p)) {
            arg[i++] = *p++;
        }
        arg[i++] = *p;
        arg[i] = '\0';
        switch (arg[i - 1]) {
            case 'd':
            case 'i':
                ival = va_arg(ap, int);
                printf(arg, ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf(arg, dval);
                break;
            case 's':
                sval = va_arg(ap, char *);
                printf(arg, sval);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);
}
