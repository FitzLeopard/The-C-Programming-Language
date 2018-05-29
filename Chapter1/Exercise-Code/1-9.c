/*
 *	Date: 2018-05-29
 *	Exercise 1-9 of K&R
 *	By Rivers
*/

#include<stdio.h>

int main()
{
	int c;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			putchar(' ');
			// Omit the following blanks
			while (c == ' ') {
				c = getchar();
			}
		}

		/* If previous char is ' ', this putchar will print the
		 * following nonblank char.
		 * Otherwise, the 'if' is not executed and this putchar
		 * just prints this char.							   */
		putchar(c);
	}

	return 0;
}
