/*
 *	Date: 2018-06-08
 *	Exercise 3-1 of K&R
 *	By Rivers
*/

#include<stdio.h>

/* binsearch: search x in v with v[0] <= v[1] <= ... <= v[n - 1]
 * Only one test inside the loop								*/
int binsearch(int x, int v[], int n);
/* qSort: quick sort array a[s..e] */
void qSort(int a[], int s, int e);
int partition(int a[], int s, int e);

int main()
{
	int a[100];
	int i, n, x;

	srand((int)time(NULL));
	n = rand() % 100 + 1;
	printf("There %s %d number%s.\n", (n == 1) ? "is" : "are",
			n, (n == 1) ? "" : "s");
	for (i = 0; i < n; ++i) {
		a[i] = rand() % 1000;
	}
	qSort(a, 0, n - 1);
	printf("Enter a number that you want to search:\n");
	scanf("%d", &x);
	i = binsearch(x, a, n);
	if (i == -1) {
		printf("This number is not in a.\n");
	}
	else {
		printf("This number is a[%d].\n", i);
	}
	printf("Here is the array:\n");
	for (i = 0; i < n; ++i) {
		printf("%5d%c", a[i], (i % 10 == 9 || i == n - 1) ? '\n': ' ');
	}

	return 0;
}

/* qSort: quick sort array a[s..e] */
void qSort(int a[], int s, int e)
{
	if (s < e) {
		int k = partition(a, s, e);
		qSort(a, s, k - 1);
		qSort(a, k + 1, e);
	}
}

int partition(int a[], int s, int e)
{
	int i = s - 1, j = s, key = a[e];
	for (j = s; j < e; ++j) {
		if (a[j] <= key) {
			++i;
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
	int tmp = a[i + 1];
	a[i + 1] = a[j];
	a[j] = tmp;

	return i + 1;
}

/* binsearch: find x in v[0] <= v[1] <= .. <= v[n - 1] */
int binsearch(int x, int v[], int n)
{
	int left = 0, right = n - 1, mid = (left + right) / 2;

	while (left < right) {
		mid = (left + right) / 2;
		if (v[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	if (v[left] == x) {
		return left;
	}
	else {
		return -1;
	}
}
