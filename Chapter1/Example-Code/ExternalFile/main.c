/*
 *	Date: 2018-06-01
 *	Page 31 of K&R
 *	By Rivers
*/

#include<stdio.h>
#include"external.h"

extern char longest[];
int max;

/* print longest input line; specialized version */
int main()
{
	int len;

	max = 0;
	while ((len = Getline()) > 0) {
		if (len > max) {
			max = len;
			copy();
		}
	}
	if (max > 0) {
		printf("%s", longest);
	}

	return 0;
}
