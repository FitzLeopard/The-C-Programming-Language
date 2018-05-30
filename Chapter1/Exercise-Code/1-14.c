/*
 *	Date: 2018-05-30
 *	Exercise 1-14 of K&R
 *	By Rivers
*/

#include<stdio.h>

/* Print a histogram of the frequencies of different characters
 * Horizontal bars											   */

#define CHARNUM	26

int main()
{
	int NumChar[CHARNUM];
	int c, i, j;
	
	/* Initialization */
	for (i = 0; i < CHARNUM; ++i) {
		NumChar[i] = 0;
	}

	/* Count the frequency */
	while ((c = getchar()) != EOF) {
		if (c >= 'a' && c <= 'z') {
			++NumChar[c - 'a'];
		}
	}

	/* Display the histogram with horizontal bars*/
	for (i = 0; i < CHARNUM; ++i) {
		printf("%2c ", 'a' + i);
		for (j = 0; j < NumChar[i]; ++j) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
