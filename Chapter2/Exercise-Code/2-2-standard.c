/*
 *	Date:	2018-06-07
 *	Standard solution to Exercise 2-2
 *	By Rivers
*/

#include<stdio.h>

#define MAXLINE 1000

enum loop { NO, YES };

int Getline(char s[], int lim);

int main()
{
	char s[MAXLINE];

	printf("%d\n", Getline(s, MAXLINE));
	printf("%s", s);

	return 0;
}
int Getline(char s[], int lim)
{
	enum loop okloop = YES;
	int	i = 0, c = 0;
	while (okloop == YES) {
		if (i >= lim - 1) {
			okloop = NO;
		}
		else if ((c = getchar()) == '\n') {
			okloop = NO;
		}
		else if (c == EOF) {
			okloop = NO;
		}
		else {
			s[i] = c;
			++i;
		}
	}
	if (c == '\n') {
		s[i] = c; 
		++i;
	}
	s[i] = '\0';
	return i;
}
