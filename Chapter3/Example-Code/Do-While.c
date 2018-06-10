/*
 *	Date: 2018-06-09
 *	Page 64 of K&R
 *	By Rivers
*/

#include<stdio.h>
#include<limits.h>
#include<string.h>

#define MAX 1000

/* itoa: convert integer to string */
void itoa(int n, char s[]);
/* reverse: reverse s in place */
void reverse(char s[]);

int main()
{
	char s[MAX];
	int n;

	itoa(INT_MIN, s);
	printf("int min: %d is converted to %s.\n", INT_MIN, s);

	printf("Enter a number:\n");
	scanf("%d", &n);
	itoa(n, s);
	printf("%s\n", s);

	return 0;
}

/* itoa: convert integer to string */
void itoa(int n, char s[])
{
	int sign = n, i = 0;

	if (sign < 0) {
		n = -n;
	}
	do {
		s[i++] = '0' + n % 10;
	}
	while ((n /= 10) != 0);
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
