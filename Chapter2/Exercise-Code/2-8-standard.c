/*
 *	Date: 2018-06-07
 *	Standard Solution to Exercise 2-8 of K&R
 *	By Rivers
*/

#include<stdio.h>

unsigned rightrot(unsigned x, int n);
int wordlength();

int main()
{
	unsigned x;
	int n;

	scanf("%u %d", &x, &n);
	printf("%u", rightrot(x, n));

	return 0;
}

unsigned rightrot(unsigned x, int n)
{
	int length = wordlength();	
	unsigned i = 0;

	n %= length;
	while (n-- > 0) {
		i = (1 & x) << (length - 1);
		x >>= 1;
		x |= i;
	}
	return x;
}

int wordlength()
{
	unsigned x = ~0;
	int i = 0;

	for (i = 1; (x = x >> 1) > 0; ++i)
		;
	return i;
}
