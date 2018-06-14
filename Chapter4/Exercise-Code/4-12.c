/*
 *	Date: 2018-06-14
 *	Exercise 4-12 of K&R
 *	By Rivers
*/

#include<stdio.h>

#define MAX 100

int itoa(int i, char s[], int b);

int main()
{
	char s[MAX];
	int i;

	scanf("%d", &i);
	itoa(i, s, 0);
	printf("%s\n", s);

	return 0;
}

/* itoa: convert integer i to string s, start from s[b]
 * return index of the end of the number 			  */
int itoa(int i, char s[], int b)
{
	if (i < 0) {
		s[b++] = '-';
		i = -i;
	}
	if (i / 10) {
		b = itoa(i / 10, s, b) + 1;
	}
	s[b] = i % 10 + '0';
	s[b + 1] = '\0';
	return b;
}

