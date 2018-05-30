/*
 *	Date: 2018-05-30
 *	Exercise 1-14 of K&R
 *	By Rivers
*/

#include<stdio.h>

/* Print a histogram of the frequencies of different characters
 * Vertical bars											   */

#define CHARNUM	26

int main()
{
	int NumChar[CHARNUM];
	int c, i, j, max;
	
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

	/* Display the histogram with vertical bars*/
	// Find the max frequency
	max = 0;
	for (i = 0; i < CHARNUM; ++i) {
		if (NumChar[i] > max) {
			max = NumChar[i];
		}
	}
	// Display the bars
	for (i = max; i > 0; --i) {
		for (j = 0; j < CHARNUM; ++j) {
			if (NumChar[j] >= i) {
				printf(" * "); 
			}
			else {
				printf("%3s", " ");
			}
		}
		printf("\n");
	}
	// Display the bottom(char) of the histogram
	for (i = 0; i < CHARNUM; ++i) {
		printf(" %c ", 'a' + i);
	}
	printf("\n");

	return 0;
}
