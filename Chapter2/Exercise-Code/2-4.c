/*
 *	Date: 2018-06-04
 *	Exercise 2-4 of K&R
 *	By Rivers
*/

#include<stdio.h>

#define MAXLINE 1000

/* delete any character in s2 from s1 */
void squeeze(char s1[], const char s2[]);
/* determine whether c is in s */
int In(char c, const char s[]);
int main()
{
	char s1[MAXLINE], s2[MAXLINE];

	fgets(s1, MAXLINE, stdin);
	fgets(s2, MAXLINE, stdin);
	squeeze(s1, s2);
	printf("%s\n", s1);

	return 0;
}

/* delete any character in s2 from s1 */
void squeeze(char s1[], const char s2[])
{
	int i = 0, j = 0;

	for (i = j = 0; s1[i] != '\0'; ++i) {
		if (!In(s1[i], s2)) {
			s1[j++] = s1[i];
		}
	}
	s1[j] = '\0';
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

