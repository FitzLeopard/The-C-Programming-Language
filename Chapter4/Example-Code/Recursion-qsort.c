/*
 *	Date: 2018-06-14
 *	Page 87 of K&R 
 *	By Rivers
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100

void Qsort(int v[], int left, int right);
void swap(int v[], int a, int b);

int main()
{
	srand((int) time(NULL));
	int n = rand() % MAX, i;
	int v[MAX];

	for (i = 0; i < n; ++i) {
		v[i] = rand() % 10000;
	}
	printf("There %s %d element%s.\n",
			(n == 1) ? "is" : "are",
			n,
			(n == 1) ? "" : "s");
	for (i = 0; i < n; ++i) {
		printf("%5d%c", v[i], (i % 10 == 9 || i == n - 1) ? '\n' : ' ');
	}
	Qsort(v, 0, n - 1);
	printf("Now we sort the array.\n");
	for (i = 0; i < n; ++i) {
		printf("%5d%c", v[i], (i % 10 == 9 || i == n - 1) ? '\n' : ' ');
	}
	for (i = 0; i < n - 1; ++i) {
		if (v[i] > v[i + 1]) {
			printf("Sorting failed.\n");
			return 0;
		}
	}
	printf("Sorting succeeded.\n");

	return 0;
}

void Qsort(int v[], int left, int right)
{
	int i, last;

	if (left >= right) {
		return;
	}
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; ++i) {
		if (v[i] <= v[left]) {
			swap(v, i, ++last);
		}
	}
	swap(v, last, left);
	Qsort(v, left, last - 1);
	Qsort(v, last + 1, right);
}


void swap(int v[], int a, int b)
{
	int tmp;

	tmp = v[a];
	v[a] = v[b];
	v[b] = tmp;
}
