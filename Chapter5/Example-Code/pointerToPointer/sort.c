/*
 *	Date: 2018-06-18
 *	Page 110 of K&R
 *	By Rivers
*/

#include<string.h>

void swap(char *lineptr[], int a, int b);

void qsort(char *lineptr[], int left, int right)
{
	int i, last;

	if (left >= right) {
		return;
	}
	swap(lineptr, left, (left + right) / 2);
	i = last = left;
	for (i = left + 1; i <=right; ++i) {
		if (strcmp(lineptr[i], lineptr[left]) <= 0) {
			swap(lineptr, i, ++last);
		}
	}
	swap(lineptr, left, last);
	qsort(lineptr, left, last - 1);
	qsort(lineptr, last + 1, right);
}

/* interchange lineptr[a] and lineptr[b] */
void swap(char *lineptr[], int a, int b)
{
	char * tmp;

	tmp = lineptr[a];
	lineptr[a] = lineptr[b];
	lineptr[b] = tmp;
}
