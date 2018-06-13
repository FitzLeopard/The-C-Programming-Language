/*
 *	Date: 2018-06-12
 *	Page 82 of K&R
 *	By Rivers
*/

#include<stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];		/* buffer for ungetch */
int bufp = 0;			/* next free position in buf */

int getch(void) /* get a (possibly pushed back) char */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)		/* push char back on input */
{
	if (bufp >= BUFSIZE) {
		printf("Error: ungetch: too many characters\n");
	}
	else {
		buf[bufp++] = c;
	}
}

