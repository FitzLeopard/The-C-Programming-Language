/*
 *	Date: 2018-06-17
 *	Page 106 of K&R
 *	By Rivers
*/

#include<stdio.h>

#define MAX 1000

void Strcpy(char *s, char *t);

int main()
{
	char s[MAX], t[MAX];

	fgets(s, MAX, stdin);
	fgets(t, MAX, stdin);
	Strcpy(s, t);
	printf("%s", s);

	return 0;
}

void Strcpy(char *s, char *t)
{
	while (*s++ = *t++)
		;
}

