/*
 *  Date: 2018-06-25
 *  Exercise 1-23 of K&R revisited
 *  By Rivers
*/

#include <stdio.h>

void RmCom(void);
void RmLine(void);
void RmBlock(void);
void EchoStr(int);

int main()
{
    int c;

    while ((c = getchar()) != EOF) { 
        if (c == '/') { // maybe it is a comment
            RmCom();
        }
        else if (c == '\'' || c == '"') {   // echo the string or char
			putchar(c);
            EchoStr(c);
			putchar(c);
        }
        else {      // ordinary char
            putchar(c);
        }
    }

    return 0;
}

/* RmCom: remove potential line or block comment */
void RmCom(void)
{
    int c;

    if ((c = getchar()) == '/') {
        RmLine();
    }
    else if (c = '*') {
        RmBlock();
    }
    else {
        putchar('/');
        putchar(c);
    }
}

/* RmLine: remove line comment */
void RmLine(void)
{
    int c;

    while ((c = getchar()) != '\n')
        ;
}

/* RmBlock: remove block comment */
void RmBlock(void)
{
    int c, clast = 0;

    while ((c = getchar()) != EOF) {
        if (clast == '*' && c == '/') {
            return;
        }
        clast = c;
    }
}

/* EchoStr: echo the whole string or char
   Ignore escape sequence               */
void EchoStr(int x)
{
    int c;

    while ((c = getchar()) != EOF && c != x) {
        putchar(c);
        if (c == '\\') {
            putchar(getchar());
        }
    }
}