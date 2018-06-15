/*
 *	Date: 2018-06-15
 *	Page 89 of K&R
 *	By Rivers
*/

#include<stdio.h>

#define forever for (;;)
#define deadloop forever
#define max(A, B) ((A > B) ? (A) : (B))

int main()
{
	int a, b;

	scanf("%d%d", &a, &b);
	printf("%d\n", max(a, b));

	return 0;
}
