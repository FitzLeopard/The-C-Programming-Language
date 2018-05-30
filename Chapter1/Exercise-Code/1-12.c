/*
 *	Date: 2018-05-30
 *	Exercise 1-12 of K&R
 *	By Rivers
*/

#include<stdio.h>

#define IN 	1
#define OUT	0

int main()
{
	int state, c;

	state = OUT;		// Initialization
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state == IN) {		// Just get out of a word
				printf("\n");
			}
			state = OUT;
		}
		else {			// Print c and refresh state
			putchar(c);
			state = IN;
		}
	}

	return 0;
}
