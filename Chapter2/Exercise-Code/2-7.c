/*
 *	Date: 2018-06-06
 *	Exercise 2-7 of K&R
 *	By Rivers
*/

#include<stdio.h>

/* invert: return x with the n bits that begin at position p inverted */
int invert(int x, int p, int n)
{
	return x ^ (~(~0 << n) << (p - n + 1));
}

int main()
{
	int x, p, n;

	scanf("%d%d%d", &x, &p, &n);
	printf("%d\n", invert(x, p, n));

	return 0;
}
