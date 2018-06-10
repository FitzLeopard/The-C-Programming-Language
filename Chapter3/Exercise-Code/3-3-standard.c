/*
 *	Date: 2018-06-09
 *	Exercise 3-3 of K&R
 *	By Rivers
*/

#include<stdio.h>
#include<ctype.h>

#define MAXLINE 1000

/* expand: expand shrthand notation in s1 like a-z and 1-9
 * into equivalent complete list						*/
void expand(const char s1[], char s2[]);

int main()
{
	char s1[MAXLINE], s2[MAXLINE];

	fgets(s1, MAXLINE, stdin);
	expand(s1, s2);
	printf("%s", s2);

	return 0;
}

/* expand: expand shorthand notation in s1 like a-z and 1-9
 * into equivalent complete list						*/
void expand(const char s1[], char s2[])
{
	int c, i = 0, j = 0;

	while ((c = s1[i++]) != '\0') {
		if (s1[i] == '-' && s1[i + 1] > c) {
			while (c < s1[i + 1]) {
				s2[j++] = c++;
			}
			++i;
		}
		else {
			s2[j++] = c;
		}
	}
	s2[j] = '\0';
}
