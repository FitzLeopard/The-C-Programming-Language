/*
 *	Date: 2018-06-20
 *	Exercise 5-11 of K&R
 *	By Rivers
*/

#include<stdio.h>
#include"tab.h"

void entab(char tab[])
{
	int pos = 0, c, nb = 0, nt = 0;

	while ((c = getchar()) != EOF) {
		switch (c) {
			case ' ':
				++pos;
				if (istabstop(tab, pos) == YES) {
					nb = 0;
					++nt;
				}
				else {
					++nb;
				}
				break;
			case '\t':
				putchar(c);
				nb = 0;
				for (; nt != 0; --nt) {
					putchar('\t');
				}
				while (istabstop(tab, pos) != YES) {
					++pos;
				}
				break;
			case '\n':
				putchar(c);
				pos = 0;
				break;
			default:
				for (; nt != 0; --nt) {
					putchar('\t');
				}
				for (; nb != 0; --nb) {
					putchar(' ');
				}
				putchar(c);
				++pos;
		}
	}
}
