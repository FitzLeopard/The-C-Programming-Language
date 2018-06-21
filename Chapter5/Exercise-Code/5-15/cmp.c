/*
 *	Date: 2018-06-21
 *	Page 119 of K&R
 *	By Rivers
*/

#include<stdlib.h>
#include<ctype.h>

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

int strcasecmp(const char * a, const char * b)
{
	while (tolower(*a) == tolower(*b) && *a != '\0' && *b != '\0') {
		++a;
		++b;
	}
	if (tolower(*a) == tolower(*b)) {
		return 0;
	}
	else if (tolower(*a) < tolower(*b)) {
		return -1;
	}
	else {
		return 1;
	}
}
