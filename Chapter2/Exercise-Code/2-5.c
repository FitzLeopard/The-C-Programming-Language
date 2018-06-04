/*
 *	Date: 2018-06-04
 *	Exercise 2-5 of K&R
 *	By Rivers
*/

#include<stdio.h>

#define MAXLINE 1000

/* The position of the first element in s1 that is contained in s2 */
int any(const char s1[], const char s2[]);
/* determine whether c is in s */
int In(char c, const char s[]);

int main()
{
	char s1[MAXLINE], s2[MAXLINE];

	fgets(s1, MAXLINE, stdin);
	fgets(s2, MAXLINE, stdin);
	printf("%d\n", any(s1, s2));

	return 0;
}

/* The position of the first element in s1 that is contained in s2 */
int any(const char s1[], const char s2[])
{
	for (int i = 0; s1[i] != '\0'; ++i) {
		if (In(s1[i], s2)) {
			return i + 1;
		}
	}

	return -1;
}

/* determine whether c is in s */
int In(char c, const char s[])
{
	for (int i = 0; s[i] != '\0'; ++i) {
		if (c == s[i]) {
			return 1;
		}
	}

	return 0;
}

