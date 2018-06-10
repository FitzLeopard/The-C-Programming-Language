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
	int i, j, c;

	for (i = j = 0; s1[i] != '\0'; ++i, ++j) {
		if (s1[i] == '-') {
			if (i > 0 &&
				(isdigit(s1[i - 1]) && isdigit(s1[i + 1]) ||
				isalpha(s1[i - 1]) && isalpha(s1[i + 1])) && 
				s1[i - 1] < s1[i + 1]) {
				for (c = s1[i - 1] + 1; c <= s1[i + 1]; ++c, ++j) {
					s2[j] = c;
				}
				++i;
				--j;
			}
			else {
				s2[j] = s1[i];
			}
		}
		else {
			s2[j] = s1[i];
		}
	}
	s2[j] = '\0';
}
