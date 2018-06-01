/*
 *	Date: 2018-06-01
 *	Exercise 1-21 of K&R
 *	By Rivers
*/

#include<stdio.h>

#define TABLEN 4

void entab(int, int *);

int main()
{
	int c;
	int len;		/* length of characters seen so far in the current line. */

	len = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t') {
			entab(c, &len);
		}
		else {
			putchar(c);
			if (c == '\n') {
				len = 0;
			}
			else {
				++len;
			}
		}
	}

	return 0;
}

/* entab: use the minimum number of tabs and blanks
 * to achieve the same spacing.
 * change len
 * when either one blank or one tab will fit, I prefer
 * tab.												*/
void entab(int c, int * len)
{
	int ori = (*len);

	/* get proper len */
	do {
		if (c == ' ') {
			++(*len);
		}
		else {
			(*len) = ((*len) / TABLEN + 1) * TABLEN;
		}
	} while ((c = getchar()) == ' ' || c == '\t');

	/* entab */
	for (; (ori / TABLEN + 1) * TABLEN <= *len; ori = (ori / TABLEN + 1) * TABLEN) {
		putchar('\t');
	}
	for (; ori < *len; ++ori) {
		putchar(' ');
	}
	putchar(c);
	++(*len);
}
