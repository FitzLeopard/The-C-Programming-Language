/*
 *	Date: 2018-06-14
 *	Page 87 of K&R
 *	By Rivers
*/

#include<stdio.h>
#include<limits.h>

void printd(int n);

int main()
{
	int n;

	//scanf("%d", &n);
	printd(INT_MAX);

	return 0;
}

/* printd: print n in decimal */
void printd(int n)
{
	if (n < 0) {
		putchar('-');
		n = -n;
	}
	if (n / 10) {
		printd(n / 10);
	}
	putchar(n % 10 + '0');
}
