/*
 *	Date: 2018-06-01
 *	Page 31 of K&R
 *	By Rivers
*/

#include<stdio.h>
#include"external.h"

char line[MAXLINE];

/* Getline: specialized version */
int Getline()
{
	int c, i;

	for (i = 0; i < MAXLINE - 1
		&& (c = getchar()) != EOF && c != '\n'; ++i) {
			line[i] = c;
	}

	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}
