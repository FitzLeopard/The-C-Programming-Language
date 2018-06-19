/*
 *	Date: 2018-06-19
 *	Page 115 of K&R
 *	By Rivers
*/

#include<stdio.h>

int main(int argc, char *argv[])
{
	int i = 1;

	for (i = 1; i < argc; ++i) {
		printf("%s%s", argv[i], (i == argc - 1) ? "\n" : " ");
	}

	return 0;
}
