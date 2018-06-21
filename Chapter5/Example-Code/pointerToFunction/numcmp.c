/*
 *	Date: 2018-06-21
 *	Page 119 of K&R
 *	By Rivers
*/

#include<stdlib.h>

int numcmp(char *a, char *b)
{
	int ai = atoi(a);
	int bi = atoi(b);

	if (ai < bi) {
		return -1;
	}
	else if (ai > bi) {
		return 1;
	}
	else {
		return 0;
	}
}
