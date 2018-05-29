/*
 * 	Date: 2018-05-29
 * 	Page 16 of K&R
 * 	By Rivers
*/

#include<stdio.h>

int main()
{
	int c;

	c = getchar();
	while (c != EOF) {
		putchar(c);
		c = getchar();
	}

	return 0;
}
