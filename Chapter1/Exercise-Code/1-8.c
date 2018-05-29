/*
 *	Date: 2018-05-29
 *	Exercise 1-8 of K&R
 *	By Rivers
*/

#include<stdio.h>

int main()
{
	int nb, nl, nt, c;
	/*
	 *	nb for number of blanks
	 *	nl for number of newlines
	 *	nt for number of tabs
	*/

	nb = nl = nt = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			++nb;
		}
		if (c == '\n') {
			++nl;
		}
		if (c == '\t') {
			++nt;
		}
	}
	printf("%20s%3d\n", "Num of blanks:", nb);
	printf("%20s%3d\n", "Num of newlines:", nl);
	printf("%20s%3d\n", "Num of tabs:", nt);
	
	return 0;
}
