/*
 *	Date: 2018-05-30
 *	Standard, compact and elegant solution to
 *	Exercise 1-9 of K&R
 *	By Rivers
*/

#include<stdio.h>

/* replace consecutive blanks with one blank */
#define NONBLANK 'a'

int main()
{
	int c, clast;

	c = NONBLANK;
	while ((c = getchar()) != EOF) {
		if (c != ' ' || clast != ' ') {
			putchar(c);
		}
		clast = c;
	}

	return 0;
}
