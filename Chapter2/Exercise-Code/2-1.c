/*
 *	Date: 2018-06-02
 *	Exercise 2-1 of K&R
 *	By Rivers
*/

#include<stdio.h>

/* The Exercise asks for the range but here I only print the size. */
int main()
{
	printf("%15s = %d\n", "sizeof(char)", sizeof(char));
	printf("%15s = %d\n", "sizeof(short)", sizeof(short));
	printf("%15s = %d\n", "sizeof(int)", sizeof(int));
	printf("%15s = %d\n", "sizeof(long)", sizeof(long));
	printf("%15s = %d\n", "sizeof(float)", sizeof(float));
	printf("%15s = %d\n", "sizeof(double)", sizeof(double));
	printf("%15s = %d\n", "sizeof(long double)", sizeof(long double));
	
	return 0;
}
