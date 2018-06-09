/*
 *	Date: 2018-06-09
 *	Page 62 of K&R
 *	By Rivers
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100

/* shellsort: sort v[0], v[1], ... , v[n - 1] into increasing order */
void shellsort(int v[], int n);

int main()
{
	int v[MAX], n, i, flag = 1;

	srand((int)time(NULL));
	n = rand() % 100 + 1;
	for (i = 0; i < n; ++i) {
		v[i] = rand() % 1000;
		printf("%4d%c", v[i], (i % 10 == 9 || i == n - 1) ? '\n' : ' ');
	}
	printf("Now we sort it:\n");
	shellsort(v, n);
	for (i = 0; i < n; ++i) {
		if (i < n - 1 && v[i] > v[i + 1]) {
			flag = 0;
		}
		printf("%4d%c", v[i], (i % 10 == 9 || i == n - 1) ? '\n' : ' ');
	}
	printf("Sorting %s.", (flag) ? "succeeded": "failed");
	
	return 0;
}

/* shellsort: sort v[0], v[1], ... , v[n - 1] into increasing order */
void shellsort(int v[], int n)
{
	int gap, i, j, tmp;

	for (gap = n / 2; gap > 0; gap /= 2) {
		for (i = gap; i < n; ++i) {
			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
				tmp = v[j];	
				v[j] = v[j + gap];
				v[j + gap] = tmp;
			}
		}
	}
}
