/*
 *	Date: 2018-06-18
 *	Page 109 of K&R
 *	By Rivers
*/

#include<stdio.h>
#include<string.h>

#define MAXLEN 1000

int Getline(char *, int);
char *alloc(int);

/* readline: read input lines */
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = Getline(line, MAXLEN)) > 0) {
		if (nlines >= maxlines || (p = alloc(len)) == NULL) {
			return -1;
		}
		else {
			line[len - 1] = '\0';	/* delete newlines */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
	int i;

	for (i = 0; i < nlines; ++i) {
		printf("%s\n", lineptr[i]);
	}
}
