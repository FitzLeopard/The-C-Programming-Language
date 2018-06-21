/*
 *	Date: 2018-06-21
 *	Exercise 5-15 of K&R
 *	By Rivers
*/

#include<ctype.h>

void Fold(char *lineptr[], int nlines)
{
	int i;
	char *line;

	for (i = 0; i < nlines; ++i) {
		line = lineptr[i];
		while (*line) {
			*line = tolower(*line);
			++line;
		}
	}
}
