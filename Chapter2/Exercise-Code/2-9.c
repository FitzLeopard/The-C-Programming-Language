/*
 *	Date: 2018-06-07
 *	Exercise 2-9 of K&R
 *	By Rivers
*/

#include<stdio.h>

int bitcount(unsigned x);

int main()
{
	unsigned x;

	scanf("%u", &x);
	printf("%u", bitcount(x));

	return 0;
}

int bitcount(unsigned x)
{
	int i = 0;

	for (i = 0; x > 0; x &= (x - 1), ++i)
		;
	return i;
}
