/*
 *	Date: 2017-06-18
 *	Page 108 of K&R
 *	By Rivers
*/

#include<stdio.h>
#include<string.h>

#define MAXLINES 5000			/* max #lines to be sorted */

char *lineptr[MAXLINES];		/* pointers to input lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
int numcmp(char *, char *);

void qsort(void *lineptr[], int left, int right, int (*)(void *, void *));

/* sort input lines */
int main(int argc, char *argv[])
{
	int nlines;		/* number of input lines read */
	int numeric = 0;

	if (argc > 1 && strcmp(argv[1], "-n") == 0) {
		numeric = 1;
	}
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort((void **)lineptr, 0, nlines - 1, 
				(int (*)(void *, void *))(numeric ? numcmp : strcmp));
		writelines(lineptr, nlines);
		return 0;
	}
	else {
		printf("Error: input too big to sort.\n");
		return 1;
	}
}

