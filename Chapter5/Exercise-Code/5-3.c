/*
 *	Date: 2018-06-17
 *	Exercise 5-3 of K&R
 *	By Rivers
*/

#include<stdio.h>

#define MAX 1000

void Strcat(char *s, char *t);

int main()
{
	char s[MAX], t[MAX];

	fgets(s, MAX, stdin);
	fgets(t, MAX, stdin);
	Strcat(s, t);
	printf("%s", s);

	return 0;
}

/* Strcat: concatenate t to the end of s */
void Strcat(char *s, char *t)
{
	while (*s) {
		++s;
	}
	while (*s++ = *t++)
		;
}
