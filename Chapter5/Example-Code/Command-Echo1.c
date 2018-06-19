/*
 *	Date: 2018-06-19
 *	Page 115 of K&R
 *	By Rivers
*/

#include<stdio.h>

/* echo: command line argument, version 1 */
int main(int argc, char *argv[])
{
	while (--argc > 0) {
		printf("%s%s", *++argv, (argc > 1) ? " " : "\n");
	}

	return 0;
}
