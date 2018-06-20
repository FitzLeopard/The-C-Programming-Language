/*
 *	Date: 2018-06-20
 *	Exercise 5-11 of K&R
 *	By Rivers
*/

#include<stdio.h>
#include"tab.h"

void detab(char tab[])
{
	int pos = 0, c;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			do {
				putchar(' ');
			} while (istabstop(tab, ++pos) != YES);
		}
		else {
			putchar(c);
			if (c == '\n') {
				pos = 0;
			}
			else {
				++pos;
			}
		}
	}
}

