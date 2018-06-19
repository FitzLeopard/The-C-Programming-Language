/*
 *	Date: 2018-06-19
 *	Page 116 of K&R
 *	By Rivers
*/

#include<stdio.h>

int main(int argc, char *argv[])
{
	while (--argc > 0) {
		printf(argc == 1 ? "%s\n" : "%s ", *++argv);
	}

	return 0;
}
