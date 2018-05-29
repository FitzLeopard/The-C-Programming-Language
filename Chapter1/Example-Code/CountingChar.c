/*
 *	Date: 2018-05-29
 * 	Page 18 of K&R
 *	By Rivers
*/

#include<stdio.h>

/* count characters in input; 1st version */
int main()
{
	long nc;

	nc = 0;
	while (getchar() != EOF) {
		++nc;
	}
	printf("%ld\n", nc);

	return 0;
}
