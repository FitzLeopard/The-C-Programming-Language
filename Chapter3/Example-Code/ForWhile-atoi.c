/*
 *	Date: 2018-06-09
 *	Page 61 of K&R
 *	By Rivers
*/

#include<stdio.h>
#include<ctype.h>

#define MAXLINE 10

/* atoi: convert s to integer; version 1 */
int atoi(char s[]);

int main()
{
	char s[MAXLINE];

	fgets(s, MAXLINE, stdin);
	printf("%d\n", atoi(s));

	return 0;
}

/* atoi: convert s to integer; version 1 */
int atoi(char s[])
{
	int i, n, sign;

	for (i = 0; isspace(s[i]); ++i)	/* skip space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '-' || s[i] == '+') {	/* skip sign */
		++i;
	}
	for (n = 0; isdigit(s[i]); ++i) {
		n = 10 * n + s[i] - '0';
	}
	return sign * n;
}
