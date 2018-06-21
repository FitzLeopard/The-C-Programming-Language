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

void qsort(void *lineptr[], int left, int right, int (*)(void *, void *), int);

/* sort input lines */
int main(int argc, char *argv[])
{
	int nlines;		/* number of input lines read */
	int numeric = 0, reverse = 1;

	while (--argc > 0) {
		if ((*++argv)[0] != '-') {
			printf("Error: argument format: -r -n\n");
			return 1;
		}
		while (*++argv[0]) {
			switch (*argv[0]) {
				case 'n':
					numeric = 1;
					break;
				case 'r':
					reverse = -1;
					break;
				default:
					printf("Error: unknown argument\n");
					return 2;
			}
		}
	}
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort((void **)lineptr, 0, nlines - 1, 
				(int (*)(void *, void *))(numeric ? numcmp : strcmp), reverse);
		writelines(lineptr, nlines);
		return 0;
	}
	else {
		printf("Error: input too big to sort.\n");
		return 1;
	}
}

