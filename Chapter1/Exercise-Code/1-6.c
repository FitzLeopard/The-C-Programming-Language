/*
 *	Date: 2018-05-29
 *	Exercise 1-6 of K&R
 * 	By Rivers
*/

#include<stdio.h>

int main()
{
	int c;

	while (c = getchar() != EOF)
		printf("%d", c);
	printf("%d", c);

	return 0;
}
