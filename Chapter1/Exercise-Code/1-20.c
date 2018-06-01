/*
 *	Date: 2018-06-01
 *	Exercise 1-20 of K&R
 *	By Rivers
*/

#include<stdio.h>

#define TABLEN 4

int main()
{
	int len;		/* the length of all the charcters seen so far
					 * in the current line.						*/
	int next;		/* the next place for the blank to replace the tab */
	int c;

	len = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			next = (len / TABLEN + 1) * TABLEN;
			for (; len < next; ++len) {
				putchar(' ');
			}
		}
		else {
			putchar(c);
			if (c == '\n') {
				len = 0;
			}
			else {
				++len;
			}
		}
	}

	return 0;
}
