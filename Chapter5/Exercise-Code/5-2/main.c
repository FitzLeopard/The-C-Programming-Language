/*
 *	Date: 2018-06-15
 *	Exercise 5-2 of K&R
 *	By Rivers
*/

#include<stdio.h>

#define SIZE 1000

int getfloat(double * pf);

int main()
{
	double z[SIZE];
	int n = 0, signal;

	for (n = 0; n < SIZE && 
			(signal = getfloat(&z[n])) != EOF &&
			signal != 0; ++n)
		;
	if (signal == 0) {
		printf("%d\n", n);
		printf("There is a nonfloat term.\n");
		return -1;
	}
	for (int i = 0; i < n; ++i) {
		printf("%6.2f%c", z[i],
				(i % 5 == 4 || i == n - 1) ? '\n' : ' ');
	}

	return 0;
}

