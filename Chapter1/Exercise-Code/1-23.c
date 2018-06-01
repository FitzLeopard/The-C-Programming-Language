/*
 *	Date: 2018-06-01
 *	Exercise 1-23 of K&R
 *	By Rivers
*/

#include<stdio.h>

#define IN_STRING	1
#define OUT_STRING	0
#define NONCHAR 0

void RmBlock();
void RmLine();

int main()
{
	int state;			/* whether the character is in a string constant or not */
	int c, clast;

	state = OUT_STRING;
	c = clast = NONCHAR;
	while ((c = getchar()) != EOF) {
		if (state == IN_STRING) {
			putchar(c);
			if (c == '\"' && clast != '\\') {
				state = OUT_STRING;
			}
		}
		else if (c == '/') {
			clast = c;
			c = getchar();
			if (c == '*' && clast == '/') {
				RmBlock();
				c = clast = NONCHAR;
			}
			else if (c == '/' && clast == '/') {
				RmLine();
				c = clast = NONCHAR;
			}
			else {
				putchar(clast);
				putchar(c);
				clast = c;
			}
		}
		else {
			putchar(c);
			clast = c;
		}
	}

	return 0;
}

/* RmBlock: remove block comment */
void RmBlock()
{
	int c, clast;
	
	c = clast = NONCHAR;
	while (!(c == '/' && clast == '*')) {
		clast = c;
		c = getchar();
	}
}

/* RmLine: remove line comment */
void RmLine()
{
	int c;

	c = NONCHAR;
	while ((c = getchar()) != '\n')
		;
	putchar(c);
}
