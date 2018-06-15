/*
 *	Date: 2018-06-15
 *	Exercise 4-14 of K&R
 *	By Rivers
*/

#include<stdio.h>

#define swap(t, x, y) {t tmp = x; x = y; y = tmp;}

int main()
{
	int x, y;

	scanf("%d%d", &x, &y);
	swap(int, x, y);
	printf("%d%d", x, y);

	return 0;
}
