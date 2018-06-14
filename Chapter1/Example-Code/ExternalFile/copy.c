/*
 *	Date: 2018-06-01
 *	Page 31 of K&R
 *	By Rivers
*/

#include"external.h"

char longest[MAXLINE];
extern char line[];

void copy(void)
{
	int i;

	i = 0;
	while ((longest[i] = line[i]) != '\0') {
		++i;
	}
}
