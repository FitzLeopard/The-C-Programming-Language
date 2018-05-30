/*
 *	Date: 2018-05-30
 *	Exercise 1-13 of K&R
 *	By Rivers
*/

#include<stdio.h>

/* Print a histogram of the lengths of words with vertical bars
 * Suppose that the length of words is at most 25			   */

#define MAXLEN 	25
// state: in or out of word
#define IN 		1
#define OUT 	0

int main()
{
	int NumLen[MAXLEN];
	int i, j, c, currLen, state, max;

	/* Count the number of words with particular length */
	currLen = 0;
	state = OUT;
	for (i = 0; i < MAXLEN; ++i) {
		NumLen[i] = 0;
	}
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (state == IN) {
				if (currLen > MAXLEN) {
					printf("Error: The word is too long!\n");
					return 1;
				}
				++NumLen[currLen - 1];
			}
			state = OUT;
			currLen = 0;
		}
		else {
			// Count length
			state = IN;
			++currLen;
		}
	}

	/* Display the histogram with vertical bars*/
	// Find the longest bar
	max = 0;
	for (i = 0; i < MAXLEN; ++i) {
		if (max < NumLen[i]) {
			max = NumLen[i];
		}
	}
	// Print the bars
	for (i = max; i > 0; --i) {
		for (j = 0; j < MAXLEN; ++j) {
			if (NumLen[j] >= i) {	// Greater than the longest length
				printf("%3s", "*");
			}
			else {
				printf("%3s", " ");
			}
		}
		printf("\n");
	}
	// Print the bottom(number) of the histogram
	for (i = 0; i < MAXLEN; ++i) {
		printf("%3d", i + 1);
	}
	printf("\n");

	return 0;
}
