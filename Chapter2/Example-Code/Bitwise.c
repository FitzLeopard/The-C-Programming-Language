/*
 *	Date: 2018-06-05
 *	Page 49 of K&R
 *	By Rivers
*/

#include<stdio.h>

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p + 1 - n)) & ~(~0 << n);
}

int main()
{
	int x, p, n;

	scanf("%d %d %d", &x, &p, &n);
	printf("%d\n", getbits(x, p, n));

	return 0;
}
