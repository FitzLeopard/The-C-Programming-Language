/*
 *	Date: 2018-06-15
 *	Page 97 of K&R
 *	By Rivers
*/

#include<stdio.h>

#define SIZE 100

int getint(int * pn);

int main()
{
	int z[SIZE], n, signal;

	for (n = 0; n < SIZE && 
			(signal = getint(&z[n])) != EOF &&
			signal != 0; ++n)
		;
	if (signal == 0) {
		printf("There is a nonnumber term.\n");
		return -1;
	}
	while (n--) {
		printf("%d%c", z[n], (n % 10 == 9 || n == 0) ? '\n' : ' ');
	}

	return 0;
}
