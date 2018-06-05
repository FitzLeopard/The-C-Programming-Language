/*
 *	Date: 2018-06-05
 *	Exercise 2-6 of K&R
 *	By Rivers
*/

#include<stdio.h>

/* setbits: return x with the n bits that begin at position p
 * set to the rightmost n bits of y, leaving the other bits unchanged. */
int setbits(int x, int p, int n, int y)
{
	x = x & ~((~(~0 << n)) << (p - n + 1));	/* set all the bits that need 
											 * changing to 0			*/
	y = (y & ~(~0 << n)) << (p - n + 1);	/* get the n rightmost bits */
	x |= y;			/* set the bits with & */

	return x;
}

int main()
{
	int x, p, n, y;

	scanf("%d %d %d %d", &x, &p, &n, &y);
	printf("%d\n", setbits(x, p, n, y));

	return 0;
}
