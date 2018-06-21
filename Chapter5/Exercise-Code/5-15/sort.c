/*
 *	Date: 2018-06-18
 *	Page 110 of K&R
 *	By Rivers
*/

#include<string.h>

void swap(void *lineptr[], int a, int b);

void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *), int reverse)
{
	int i, last;

	if (left >= right) {
		return;
	}
	swap(lineptr, left, (left + right) / 2);
	i = last = left;
	for (i = left + 1; i <=right; ++i) {
		if (reverse * (comp)(lineptr[i], lineptr[left]) <= 0) {
			swap(lineptr, i, ++last);
		}
	}
	swap(lineptr, left, last);
	qsort(lineptr, left, last - 1, comp, reverse);
	qsort(lineptr, last + 1, right, comp, reverse);
}

/* interchange lineptr[a] and lineptr[b] */
void swap(void *lineptr[], int a, int b)
{
	void * tmp;

	tmp = lineptr[a];
	lineptr[a] = lineptr[b];
	lineptr[b] = tmp;
}

