/*
 *	Date: 2018-06-17
 *	Page 106 of K&R
 *	By Rivers
*/

#include<stdio.h>

#define MAX 1000

int Strcmp(char *s, char *t);

int main()
{
	char s[MAX], t[MAX];

	fgets(s, MAX, stdin);
	fgets(t, MAX, stdin);

	printf("%d\n", Strcmp(s, t));

	return 0;
}

/* Strcmp: return <0 if s < t, return 0 if s = t, return >0 if s > t */
int Strcmp(char *s, char *t)
{
	for (; *s == *t; ++s, ++t) {
		if (*s == '\0') {
			return 0;
		}
	}
	return *s - *t;
}
