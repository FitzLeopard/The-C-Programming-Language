/*
 *	Date: 2018-05-30
 *	Exercise 1-13 of K&R
 *	By Rivers
*/

#include<stdio.h>

/* Print a histogram of the lengths of words, horizontal bars 
 * Assume the length of words is at most 25					*/

#define MAXLEN 	25
// state: in or out of a word
#define IN		1
#define OUT 	0

int main()
{
	int NumLen[MAXLEN];
	int i, j, c, currLen, state;

	// Count the number of words with particular length
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

	// Display the histogram
	for (i = 0; i < MAXLEN; ++i) {
		printf("%3d ", i + 1);
		for (j = 0; j < NumLen[i]; ++j) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
