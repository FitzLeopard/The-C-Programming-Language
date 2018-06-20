/*
 *	Date: 2018-06-20
 *	Exercise 5-11 of K&R
 *	By Rivers
*/

#include"tab.h"
#include<stdlib.h>

/* tabset: set the tab stop */
void tabset(int argc, char *argv[], char tab[])
{
	int i;

	for (i = 1; i < MAXLINE; ++i) {
		tab[i] = NO;
	}
	if (argc == 1) {
		for (i = TABSTOP; i < MAXLINE; i += TABSTOP) {
			tab[i] = YES;
		}
	}
	else {
		for (i = 1; i < argc; ++i) {
			tab[atoi(*++argv)] = YES;
		}
	}
}

int istabstop(char tab[], int pos)
{
	if (pos > MAXLINE) {
		return YES;
	}
	else {
		return tab[pos];
	}
}
