/*
 *	Date: 2018-06-09
 *	Page 63 of K&R
 *	By Rivers
*/

#include<stdio.h>
#include<string.h>

#define MAXLINE 100

/* reverse: reverse s in place */
void reverse(char s[]);

int main()
{
	char s[MAXLINE];

	fgets(s, MAXLINE, stdin);
	reverse(s);
	printf("%s", s);

	return 0;
}

/* reverse: reverse s in place */
void reverse(char s[])
{
	int i, j, c;

	for (i = 0, j = strlen(s) - 1; j > i; ++i, --j)
		c = s[i], s[i] = s[j], s[j] = c;
}
