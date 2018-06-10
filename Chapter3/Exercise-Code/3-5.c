/*
 *	Date: 2018-06-10
 *	Exercise 3-5 of K&R
 *	By Rivers
*/

#include<stdio.h>
#include<string.h>

#define MAX 1000

/* itob: convert integer n to a base b character representation
 * in string s												  */
void itob(int n, char s[], int b);
/* reverse: reverse s in place */
void reverse(char s[]);

int main()
{
	int n, b;
	char s[MAX];

	scanf("%d%d", &n, &b);
	itob(n, s, b);
	printf("%s\n", s);

	return 0;
}

/* itob: convert integer n to a base b character representation
 * in string s												  */
void itob(int n, char s[], int b)
{
	int i = 0, sign, remainder;

	sign = (n > 0) ? 1 : -1;
	do {
		remainder = sign * n % b;
		s[i++] = (remainder > 9) ? remainder - 10 + 'A': remainder + '0';
	} while ((n /= b) != 0);
	if (sign < 0) {
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);
}

/* reverse: reverse s in place */
void reverse(char s[])
{
	int i, j, c;

	for (i = 0, j = strlen(s) - 1; j > i; ++i, --j)
		c = s[i], s[i] = s[j], s[j] = c;
}
