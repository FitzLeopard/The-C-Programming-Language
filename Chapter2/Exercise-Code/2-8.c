/*
 *	Date: 2018-06-06
 *	Exercise 2-8 of K&R
 *	By Rivers
*/

#include<stdio.h>

/* return c rotated to the right by n bit positions */
unsigned rightrot(unsigned x, int n)
{
	int length = 8 * sizeof(x), lastn = 0;

	printf("length = %d\n", length);		// length of unsigned
	lastn = x & (~(~0 << n));				// get the last n bits of x
	x >>= n;
	lastn <<= length - n;					// rightrotate n bits to the left side
	x |= lastn;								// set n bits
	return x;
}

int main()
{
	unsigned x, n;

	scanf("%u%u", &x, &n);
	printf("%u\n", rightrot(x, n));

	return 0;
}
