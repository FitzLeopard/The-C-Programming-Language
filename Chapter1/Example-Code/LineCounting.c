/*
 *	Date: 2018-05-29
 *	Page 19 of K&R
 *	By Rivers
*/

#include<stdio.h>

/* count lines in input */
int main()
{
	int c, nl;

	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			++nl;
		}
	}
	printf("%d\n", nl);

	return 0;
}
