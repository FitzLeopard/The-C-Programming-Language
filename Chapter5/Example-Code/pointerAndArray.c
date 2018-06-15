/*
 *	Date: 2018-06-15
 *	Page 99 of K&R
 *	By Rivers
*/

#include<stdio.h>

int Strlen(char s[]);

int main()
{
	printf("%d\n", Strlen("Hello, world!"));

	return 0;
}

int Strlen(char *s)
{
	int n = 0;

	for (n = 0; *s != '\0'; ++s) {
		++n;
	}

	return n;
}
