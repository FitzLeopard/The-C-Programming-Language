/*
 *	Date: 2018-06-17
 *	Exercise 5-4 of K&R
 *	By Rivers
*/

#include<stdio.h>

#define MAX 1000

int strend(char *s, char *t);

int main()
{
	char s[MAX], t[MAX];

	fgets(s, MAX, stdin);
	fgets(t, MAX, stdin);
	printf("%d\n", strend(s, t));

	return 0;
}

/* strend: return 1 if t occurs at the end of s, return 0 otherwise */
int strend(char *s, char *t)
{
	char *tcp = t; 		/* a copy of t ;*/

	while (*s) {
		++s;
	}
	while (*tcp) {
		++tcp;
	}
	while (*tcp == *s && tcp != t - 1) {
		--s;
		--tcp;
	}
	if (tcp == t - 1) {
		return 1;
	}
	else {
		return 0;
	}
}

