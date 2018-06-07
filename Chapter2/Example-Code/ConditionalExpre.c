/*
 *	Date: 2018-06-07
 *	Page 52 of K&R
 *	By Rivers
*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
	int n, i;
	
	srand((int) time(NULL));
	n = rand() % 100;

	for (i = 0; i < n; ++i) {
		printf("%d%c", rand() % 32767, (i % 10 == 9 || i == n - 1) ? ('\n') : (' '));
	}
	printf("How many items do you have?\n");
	scanf("%d", &n);
	printf("There %s %d item%s.\n", (n > 1) ? ("are") : ("is"), n, (n > 1) ? ("s") : (""));

	return 0;
}
