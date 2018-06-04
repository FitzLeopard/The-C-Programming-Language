/*
 *	Date: 2018-06-04
 *	Exercise 2-3 of K&R
 *	By Rivers
*/

#include<stdio.h>
#include<ctype.h>

#define MAXLINE 1000

/* Convert a hexadecimal digits into its equivalent integer value.
 * Including an optional 0x or 0X.								*/
int htoi(const char s[]);
/* Convert one character */
int htoi_c(char c);

int main()
{
	char s[MAXLINE];

	fgets(s, MAXLINE, stdin);
	printf("Corresponding integer:\n");
	printf("%d\n", htoi(s));

	return 0;
}

/* Convert a hexadecimal digits into its equivalent integer value.
 * Including an optional 0x or 0X.								*/
int htoi(const char s[])
{
	int result = 0;
	int i = 0;

	if (s[1] == 'x' || s[1] == 'X') {
		i = 2;
	}

	while (s[i] != '\n') {
		result = result * 16 + htoi_c(s[i]);
		++i;
	}

	return result;
}

/* Convert one character */
int htoi_c(char c)
{
	if (isdigit(c)) {
		return c - '0';
	}
	c = toupper(c);
	return c - 'A' + 10;
}


