/*
 *	Date: 2017-06-18
 *	Page 108 of K&R
 *	By Rivers
*/

#include<stdio.h>

#define MAXLINES 5000			/* max #lines to be sorted */
#define MAXSTORAGE 10000		/* max #char to be stored */

char *lineptr[MAXLINES];		/* pointers to input lines */
char alloc[MAXSTORAGE];			/* alloc from main */

int readlines(char *lineptr[], char alloc[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main()
{
	int nlines;		/* number of input lines read */

	if ((nlines = readlines(lineptr, alloc, MAXLINES)) >= 0) {
		qsort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	}
	else {
		printf("Error: input too big to sort.\n");
		return 1;
	}
}

